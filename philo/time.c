/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:41:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 15:48:22 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Extremely precise usleep function
 * @param microseconds (unsigned long)
 * @return (int) 0 for succes, -1 for error
 */
int	ft_usleep(unsigned long microseconds)
{
	struct timeval	start, end;
	unsigned long	elapsed;

	if (!microseconds)
		return (-1);
	gettimeofday(&start, NULL);
	usleep(microseconds);
	gettimeofday(&end, NULL);
	elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	if (elapsed < microseconds)
		usleep(microseconds - elapsed);
	// gettimeofday(&end, NULL);
	// elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
	// printf("ft_usleep : %lu µs (requested: %lu)\n", elapsed, microseconds);
	return (0);
}
