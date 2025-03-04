/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:41:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 11:08:04 by mathispeyre      ###   ########.fr       */
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
	struct timeval	start, end;
	unsigned long	elapsed;

	if (!milliseconds)
		return (-1);
	gettimeofday(&start, NULL);
	usleep(milliseconds * 1000);
	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
	if (elapsed < milliseconds)
		usleep((milliseconds - elapsed) * 1000);
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
