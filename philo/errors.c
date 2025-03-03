/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:40:02 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 15:04:06 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_table(t_table *table)
{
	free(table);
}

/**
 * @brief Hub function for exit process (free and errors codes/printf)
 * @param exid_id (int) :
 * - 0 for total free and exit_succes,
 * - 1 cmd line error (no free)
 * @param t_table* Pointer to initialized program data structure
 * @param msg* Pointer to initialized program data structure
 * @return error_code* Program's int returned
 */
int	process_exit(int exit_id, t_table *table, char *msg)
{
	if (exit_id != 1)
		free_table(table);
	if (exit_id > 0)
	{
		if (msg)
			printf("%s\n", msg);
		return (1);
	}
	return (0);
}
