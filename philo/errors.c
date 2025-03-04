/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:40:02 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 15:42:23 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	if (exit_id == 2)
		free_table(table);
	if (exit_id > 0)
	{
		if (msg)
			printf("%s\n", msg);
		return (1);
	}
	return (exit_id);
}
