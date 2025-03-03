/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:36:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 14:37:15 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	int	nb_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_nb;
}				t_data;

/*                    INIT_AND_PARSE.C                    */
int	init_and_parse(int ac, char **av, t_data **data);

/*                         MAIN.C                         */
int	run_simulation(t_data *data);

/*                        ERRORS.C                        */
int	process_exit(int exit_id, t_data *data, char *msg);

/*                         TIME.C                         */
int	ft_usleep(long long microseconds);

/*                        UTILS.C                         */
int	ft_atoi(const char *str);

#endif
