/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:38:50 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 15:48:54 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	*table;

	table = NULL;
	if (init_and_parse(ac, av, &table) == 1)
		return (process_exit(1, table, "Invalid arguments: check count/types"));
	run_simulation(table);
	return (process_exit(0, table, NULL));
}

int	run_simulation(t_table *table)
{
	printf("Starting simulation with : %d philosophers, %d time to die, %d time to eat, %d time to sleep, %d each philo must eat\n", table->nb_philo, table->time_to_die, table->time_to_eat, table->time_to_sleep, table->min_nb_meal);
	ft_usleep(500);
	return (0);
}
