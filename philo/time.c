/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:41:04 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 15:09:04 by mathispeyre      ###   ########.fr       */
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
	unsigned long	i;

	if (microseconds < 1)
		return (-1);
	i = -1;
	while (++i != microseconds)
		usleep(1);
	return (0);
}
