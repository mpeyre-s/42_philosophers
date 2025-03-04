/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:29:15 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 15:40:55 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
