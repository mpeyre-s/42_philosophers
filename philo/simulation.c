/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:38:50 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/05 18:41:02 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Initiates philosophers simulation by creating threads
 * @param table (t_table *) Pointer to the table structure
 * @return (int) SUCCESS (0) / ERROR (-1)
 */
int	start_simulation(t_table *table)
{
	size_t	i;

	table->start_time = get_ms();
	i = -1;
	while (++i < table->nb_philo)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				&run_philosophy, table->philos[i]) != 0)
			return (ERROR);
	}
	if (pthread_create(&table->monitoring, NULL, &monitor_philosophers, table) != 0)
		return (ERROR);
	return (SUCCESS);
}

/**
 * @brief Terminates philosophers simulation by joining threads
 * @param table (t_table *) Pointer to the table structure
 * @return (int) SUCCESS (0)
 */
int	stop_simulation(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_join(table->philos[i]->thread, NULL);
	pthread_join(table->monitoring, NULL);
	return (SUCCESS);
}

/**
 * @brief Function executed by each philosopher thread during simulation
 * @param ptr (void *) Pointer to philosopher structure cast as void pointer
 * @return (void *) NULL pointer when thread completes
 */
void	*run_philosophy(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	pthread_mutex_lock(&philo->m_meal);
	philo->last_meal = philo->table->start_time;
	pthread_mutex_unlock(&philo->m_meal);
	philo->table->start_time = get_ms();
	philo->table->sim_running = TRUE;
	if (philo->table->nb_philo == 1)
		return (dead_by_overthinking(philo));
	else if (philo->id % 2)
		start_thinking(philo);
	while (is_simulation_running(philo) == TRUE)
	{
		start_eating_then_sleeping(philo);
		start_thinking(philo);
	}
	return (NULL);
}
