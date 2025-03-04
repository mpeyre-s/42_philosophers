/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:38:50 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 17:06:51 by mathispeyre      ###   ########.fr       */
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

	philo->status = LEFT_FORK;
	print_status(philo, get_ts(philo));

	philo->status = RIGHT_FORK;
	print_status(philo, get_ts(philo));

	philo->status = EATING;
	print_status(philo, get_ts(philo));
	ft_msleep(philo->table->time_to_eat);

	philo->status = SLEEPING;
	print_status(philo, get_ts(philo));
	ft_msleep(philo->table->time_to_sleep);

	philo->status = THINKING;
	print_status(philo, get_ts(philo));
	ft_msleep(philo->table->time_to_die);

	philo->status = DIED;
	print_status(philo, get_ts(philo));

	return (NULL);
}
