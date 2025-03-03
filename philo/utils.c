/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:39:22 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 14:37:51 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Converts a string to an integer
 * This function parses a string representation of an integer, handling:
 * - Leading whitespaces
 * - Optional sign (+ or -)
 * - Numeric digits
 * @param str The string to convert
 * @return int The converted integer value
 *            - Positive or negative number based on input
 *            - 0 if string starts with non-numeric char after optional sign
 */
int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result * sign);
}
