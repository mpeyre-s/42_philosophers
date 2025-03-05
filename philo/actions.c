/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:37:06 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/05 18:06:58 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dead_by_overthinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->m_forks[philo->fork[0]]);
	process_status(philo, get_ts(philo), LEFT_FORK);
	ft_msleep(philo->table->time_to_die);
	process_status(philo, get_ts(philo), DEAD);
	pthread_mutex_unlock(&philo->table->m_forks[philo->fork[0]]);
	return (NULL);
}

void	start_eating_then_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->m_forks[philo->fork[0]]);
	process_status(philo, get_ts(philo), LEFT_FORK);
	pthread_mutex_lock(&philo->table->m_forks[philo->fork[1]]);
	process_status(philo, get_ts(philo), RIGHT_FORK);
	process_status(philo, get_ts(philo), EATING);
	pthread_mutex_lock(&philo->m_meal);
	philo->last_meal = get_ms();
	pthread_mutex_unlock(&philo->m_meal);
	ft_msleep(philo->table->time_to_eat);
	process_status(philo, get_ts(philo), SLEEPING);
	pthread_mutex_unlock(&philo->table->m_forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->m_forks[philo->fork[0]]);
	ft_msleep(philo->table->time_to_sleep);
}
void	start_thinking(t_philo *philo)
{
	time_t	think_time;

	pthread_mutex_lock(&philo->m_meal);
	think_time = (philo->table->time_to_die
			- (get_ms() - philo->last_meal)
			- philo->table->time_to_eat) / 2;
	pthread_mutex_unlock(&philo->m_meal);
	if (think_time < 0)
		think_time = 0;
	if (think_time > 600)
		think_time = 200;
	process_status(philo, get_ts(philo), THINKING);
	ft_msleep(think_time);
}
