/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:40:02 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/06 14:47:11 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Frees all allocated memory from the table structure
 * @param table (t_table *) Pointer to the table structure to be freed
 * @return (void) Nothing
 * @details Frees the mutexes array, each philosopher structure,
 *          the philosophers array and finally the table structure itself.
 *          Performs NULL checks before attempting to free any memory.
 */
void	free_table(t_table *table)
{
	size_t	i;

	if (!table)
		return ;
	if (table->m_forks != NULL)
		free(table->m_forks);
	if (table->philos != NULL)
	{
		i = -1;
		while (++i < table->nb_philo)
		{
			if (table->philos[i] != NULL)
				free(table->philos[i]);
		}
		free(table->philos);
	}
	free(table);
}

/**
 * @brief Destroys all mutexes used in the philosophers simulation
 * @param table Pointer to the main table structure containing simulation data
 **/
void	destroy_mutexes(t_table *table)
{
	size_t	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		pthread_mutex_destroy(&table->m_forks[i]);
		pthread_mutex_destroy(&table->philos[i]->m_meal);
	}
	pthread_mutex_destroy(&table->m_print);
	pthread_mutex_destroy(&table->m_simulation);
}

/**
 * @brief Hub function for exit process (free and errors codes/printf)
 * @param exid_id (int) :
 * - 0 exit_succes,
 * - 1 error no free,
 * - 2 error full free,
 * @param t_table* Pointer to initialized program data structure
 * @param msg* Pointer to initialized program data structure
 * @return error_code* Program's int returned
 */
int	process_exit(int exit_id, t_table *table, char *msg)
{
	if (table != NULL)
	{
		destroy_mutexes(table);
		free_table(table);
	}
	if (exit_id > 0 && msg)
		printf("%s\n", msg);
	return (exit_id);
}
