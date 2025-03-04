/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:41:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 15:57:07 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Extremely precise sleep function in milliseconds
 * @param milliseconds (unsigned long)
 * @return (int) 0 for success, -1 for error
 */
int	ft_msleep(unsigned long milliseconds)
{
	struct timeval	start, current;
	unsigned long	elapsed;

	if (!milliseconds)
		return (-1);
	gettimeofday(&start, NULL);
	while (1)
	{
		usleep(500);
		gettimeofday(&current, NULL);
		elapsed = ((current.tv_sec - start.tv_sec) * 1000)
			+ ((current.tv_usec - start.tv_usec) / 1000);
		if (elapsed >= milliseconds)
			break ;
	}
	return (0);
}

/**
 * @brief Get time in milliseconds
 * @return struct time_t
 */
time_t	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

time_t	get_ts(time_t start, time_t now)
{
	return (now - start);
}
