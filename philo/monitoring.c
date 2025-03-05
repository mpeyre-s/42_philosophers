/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:14:49 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/05 18:44:47 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_philosophers(void *ptr)
{
	t_table	*table;

	table = (t_table *)ptr;
	set_simulation_status(table, TRUE);
	table->start_time = get_ms();
	while (1)
	{
		if (is_end_of_dinner(table) == TRUE)
			return (NULL);
		ft_msleep(10000);
	}
}

int	is_simulation_running(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->table->m_simulation);
	result = philo->table->sim_running;
	pthread_mutex_unlock(&philo->table->m_simulation);
	return (result);
}

int	is_someone_dead(t_philo *philo)
{
	time_t	time;

	time = get_ms();
	if ((time - philo->last_meal) >= philo->table->time_to_die)
	{
		set_simulation_status(philo->table, FALSE);
		process_status(philo, get_ts(philo), DEAD);
		pthread_mutex_unlock(&philo->m_meal);
		return (TRUE);
	}
	return (FALSE);
}

void	set_simulation_status(t_table *table, int status)
{
	pthread_mutex_lock(&table->m_simulation);
	table->sim_running = status;
	pthread_mutex_unlock(&table->m_simulation);
}

int	is_end_of_dinner(t_table *table)
{
	size_t	i;
	int		everybody_is_full;

	everybody_is_full = TRUE;
	i = 0;
	while (i < table->nb_philo)
	{
		pthread_mutex_lock(&table->philos[i]->m_meal);
		if (is_someone_dead(table->philos[i]))
			return (TRUE);
		if (table->min_nb_meal != -1)
			if (table->philos[i]->nb_meal < table->min_nb_meal)
				everybody_is_full = FALSE;
		pthread_mutex_unlock(&table->philos[i]->m_meal);
		i++;
	}
	if (table->min_nb_meal != -1 && everybody_is_full == TRUE)
	{
		set_simulation_status(table, FALSE);
		return (TRUE);
	}
	return (FALSE);
}
