/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:36:56 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/05 18:11:59 by mathispeyre      ###   ########.fr       */
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
# define NULL_ERROR 0
# define SUCCESS 0

typedef enum e_status
{
	DEAD = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	LEFT_FORK = 4,
	RIGHT_FORK = 5
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
	pthread_t		monitoring;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_simulation;
}				t_table;

typedef struct s_philo
{
	int				id;
	int				fork[2];
	int				nb_meal;
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

/*                      MONITOPRING.C                     */
void			*monitor_philosophers(void *ptr);
int				is_simulation_running(t_philo *philo);
int				is_someone_dead(t_philo *philo);
void			set_simulation_status(t_table *table, int status);
int				is_end_of_dinner(t_table *table);

/*                       ACTIONS.C                        */
void			*dead_by_overthinking(t_philo *philo);
void			start_eating_then_sleeping(t_philo *philo);
void			start_thinking(t_philo *philo);

/*                        ERRORS.C                        */
int				process_exit(int exit_id, t_table *table, char *msg);
void			free_table(t_table *table);
void			destroy_mutexes(t_table *table);

/*                         TIME.C                         */
int				ft_msleep(unsigned long microseconds);
time_t			get_ms(void);
time_t			get_ts(t_philo *philo);

/*                        PRINT.C                         */
void			process_status(t_philo *philo, time_t ts, t_status new);

/*                        UTILS.C                         */
int				ft_atoi(const char *str);

#endif
