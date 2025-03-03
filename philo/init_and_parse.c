/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:39:48 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 14:36:47 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Initializes the program data structure with command line arguments
 * @param ac Number of command line arguments
 * @param av Array of command line argument strings
 * @return t_info* Pointer to initialized program data structure or NULL
 */
t_data	*init_program_data(int ac, char **av, t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nb_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat_nb = ft_atoi(av[5]);
	else
		data->must_eat_nb = -1;
	return (data);
}

/**
 * @brief Check the validity of the program's data
 * @param t_data* Pointer to initialized program data structure
 * @return True if program data is valid, False otherwise.
*/
int	check_program_data(t_data *data)
{
	if (!data)
		return (1);
	if (data->nb_philosophers < 1)
		return (1);
	if (data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
		return (1);
	if (data->must_eat_nb == 0)
		return (1);
	return (0);
}

/**
 * @brief Before running the simulation, initialisation and parsing arguments
 * @param ac Number of command line arguments
 * @param av Array of command line argument strings
 * @return True if program data is valid, False otherwise.
 */
int	init_and_parse(int ac, char **av, t_data **data)
{
	if (ac < 2 || ac > 6)
		return (1);
	*data = init_program_data(ac, av, *data);
	if (*data == NULL || check_program_data(*data) == 1)
		return (1);
	//initialiser les philosophes, fourchettes etc...
	return (0);
}
