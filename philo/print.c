/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:37:19 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/05 17:29:11 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	process_status(t_philo *philo, time_t ts, t_status new)
{
	philo->status = new;
	pthread_mutex_lock(&philo->table->m_print);
	if (philo->table->sim_running || philo->status == DEAD)
	{
		if (philo->status == DEAD)
			printf("%ld %d died\n", ts, philo->id);
		else if (philo->status == EATING)
			printf("%ld %d is eating\n", ts, philo->id);
		else if (philo->status == SLEEPING)
			printf("%ld %d is sleeping\n", ts, philo->id);
		else if (philo->status == THINKING)
			printf("%ld %d is thinking\n", ts, philo->id);
		else if (philo->status == LEFT_FORK || philo->status == RIGHT_FORK)
			printf("%ld %d has taken a fork\n", ts, philo->id);
	}
	pthread_mutex_unlock(&philo->table->m_print);
}
