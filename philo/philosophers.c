/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:38:50 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 14:10:31 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (init_and_parse(ac, av, &data) == 1)
		return (process_exit(1, data, "Invalid arguments: check count/types"));
	run_simulation(data);
	return (process_exit(0, data, NULL));
}

int	run_simulation(t_data *data)
{
	printf("Starting simulation with : %d philosophers, %d time to die, %d time to eat, %d time to sleep, %d each philo must eat\n", data->nb_philosophers, data->time_to_die, data->time_to_eat, data->time_to_sleep, data->must_eat_nb);
	return (0);
}
