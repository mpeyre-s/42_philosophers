/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:12:53 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 15:30:50 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (check_program_input(ac, av) == ERROR)
		return (process_exit(1, table, "Invalid arguments: check count/types"));
	table = init_program(ac, av);
	if (!table)
		return (process_exit(1, table, "Error while initializing the program"));
	if (start_simulation(table) == ERROR)
		return (process_exit(2, table, "Error while threading the philosophy"));
	if (stop_simulation(table) == ERROR)
		return (process_exit(2, table, "Error while stopping the simulation"));
	return (process_exit(SUCCESS, table, NULL));
}
