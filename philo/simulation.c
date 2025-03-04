/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:38:50 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 16:16:43 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	start_simulation(t_table *table)
{
	size_t	i;

	i = -1;
	table->start_time = get_ms();
	while (++i < table->nb_philo)
	{
		if (pthread_create(&table->philos[i]->thread, NULL,
				&run_philosophy, table->philos[i]) != 0)
			return (ERROR);
	}
	return (SUCCESS);
}

int	stop_simulation(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_join(table->philos[i]->thread, NULL);
	return (SUCCESS);
}

void	*run_philosophy(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	printf("%ld %d awake\n", get_ts(philo->table->start_time), philo->id);
	ft_msleep(philo->table->time_to_die);
	printf("%ld %d die\n", get_ts(philo->table->start_time), philo->id);
	return (NULL);
}
