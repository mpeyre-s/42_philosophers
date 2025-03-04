/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:29:15 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 16:33:29 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Validates command-line arguments for the philosophers program
 * @param ac (int) Argument count
 * @param av (char **) Array of argument strings
 * @details Checks if:
 *          - Number of arguments is 4 or 5
 *          - First argument (number of philosophers) is > 0
 *          - All other numeric arguments are >= 0
 *          - All arguments are within INT_MAX range
 * @return (int) SUCCESS 0 if validation passes, ERROR -1 if validation fails
 */
int	check_program_input(int ac, char **av)
{
	size_t	i;
	int		nb;

	i = 0;
	if (ac - 1 < 4 || ac - 1 > 5)
		return (ERROR);
	while ((int)++i < ac)
	{
		nb = ft_atoi(av[i]);
		if ((i == 1 && nb < 1) || (i != 1 && nb < 0) || nb > INT_MAX)
			return (ERROR);
	}
	return (SUCCESS);
}
