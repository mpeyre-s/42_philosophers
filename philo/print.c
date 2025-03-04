/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:37:19 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 17:06:41 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, time_t ts)
{
	if (philo->status == DIED)
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
