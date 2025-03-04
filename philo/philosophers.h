/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:36:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 15:43:29 by mathispeyre      ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define NULL_ERROR NULL
# define SUCCESS 0

typedef enum e_status
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3
}			t_status;

typedef struct s_philo	t_philo;

typedef struct s_table
{
	size_t			nb_philo;
	time_t			start_time;
	int				sim_running;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				min_nb_meal;
	t_philo			**philos;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_simulation;
}				t_table;

typedef struct	s_philo
{
	int				id;
	int				fork[2];
	time_t			last_meal;
	t_status		status;
	pthread_t		thread;
	pthread_mutex_t	m_meal;
	struct s_table	*table;
}				t_philo;

/*                         INIT.C                         */
t_table			*init_program(int ac, char **av);
t_philo			**init_philosophers(t_table *table);
pthread_mutex_t	*init_forks(t_table *table);
int				init_global_mutexes(t_table *table);
void			assign_forks(t_philo *philo);

/*                       PARSING.C                        */
int				check_program_input(int ac, char **av);

/*                      SIMULATION.C                      */
int				start_simulation(t_table *table);
int				stop_simulation(t_table *table);
void			*run_philosophy(void *ptr);

/*                        ERRORS.C                        */
int				process_exit(int exit_id, t_table *table, char *msg);
void			free_table(t_table *table);

/*                         TIME.C                         */
int				ft_msleep(unsigned long microseconds);
time_t			get_time_in_ms(void);

/*                        UTILS.C                         */
int				ft_atoi(const char *str);

#endif
