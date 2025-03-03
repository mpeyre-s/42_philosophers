/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:40:02 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 14:10:15 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_tdata(t_data *data)
{
	free(data);
}

/**
 * @brief Hub function for exit process (free and errors codes/printf)
 * @param exid_id (int) :
 * - 0 for total free and exit_succes,
 * - 1 cmd line error (no free)
 * @param t_data* Pointer to initialized program data structure
 * @param msg* Pointer to initialized program data structure
 * @return error_code* Program's int returned
 */
int	process_exit(int exit_id, t_data *data, char *msg)
{
	if (exit_id != 1)
		free_tdata(data);
	if (exit_id > 0)
	{
		if (msg)
			printf("%s\n", msg);
		return (1);
	}
	return (0);
}
