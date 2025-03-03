/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:39:48 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 15:06:15 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Initializes the program data structure with command line arguments
 * @param ac Number of command line arguments
 * @param av Array of command line argument strings
 * @return t_table* Pointer to initialized program data structure or NULL
 */
t_table	*init_program_data(int ac, char **av, t_table *table)
{
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		table->min_nb_meal = ft_atoi(av[5]);
	else
		table->min_nb_meal = -1;
	return (table);
}

/**
 * @brief Check the validity of the program's data
 * @param t_table* Pointer to initialized program data structure
 * @return True if program data is valid, False otherwise.
*/
int	check_program_data(t_table *data)
{
	if (!data)
		return (1);
	if (data->nb_philo < 1)
		return (1);
	if (data->time_to_die < 0 || data->time_to_eat < 0
		|| data->time_to_sleep < 0)
		return (1);
	if (data->min_nb_meal == 0)
		return (1);
	return (0);
}

/**
 * @brief Before running the simulation, initialisation and parsing arguments
 * @param ac Number of command line arguments
 * @param av Array of command line argument strings
 * @param t_table* Pointer to initialized program data structure
 * @return True if program data is valid, False otherwise.
 */
int	init_and_parse(int ac, char **av, t_table **data)
{
	if (ac < 2 || ac > 6)
		return (1);
	*data = init_program_data(ac, av, *data);
	if (*data == NULL || check_program_data(*data) == 1)
		return (1);
	//initialiser les philosophes, fourchettes etc...
	return (0);
}
