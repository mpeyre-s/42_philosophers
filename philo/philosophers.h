/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:36:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/03 15:07:06 by mathispeyre      ###   ########.fr       */
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

typedef struct s_table
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_nb_meal;
}				t_table;

/*                    INIT_AND_PARSE.C                    */
int	init_and_parse(int ac, char **av, t_table **table);

/*                         MAIN.C                         */
int	run_simulation(t_table *table);

/*                        ERRORS.C                        */
int	process_exit(int exit_id, t_table *table, char *msg);

/*                         TIME.C                         */
int	ft_usleep(unsigned long microseconds);

/*                        UTILS.C                         */
int	ft_atoi(const char *str);

#endif
