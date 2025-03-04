/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathispeyre <mathispeyre@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:39:48 by mathispeyre       #+#    #+#             */
/*   Updated: 2025/03/04 15:29:10 by mathispeyre      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_table	*init_program(int ac, char **av)
{
	size_t	i;
	t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	i = 1;
	if (!table)
		return (NULL_ERROR);
	table->nb_philo = ft_atoi(av[i++]);
	table->time_to_die = ft_atoi(av[i++]);
	table->time_to_eat = ft_atoi(av[i++]);
	table->time_to_sleep = ft_atoi(av[i++]);
	table->min_nb_meal = -1;
	if (ac == 6)
		table->min_nb_meal = ft_atoi(av[i]);
	table->philos = init_philosophers(table);
	if (!table->philos)
		return (NULL_ERROR);
	if (!init_global_mutexes(table))
		return (NULL_ERROR);
	table->sim_running = FALSE;
	return (table);
}

t_philo	**init_philosophers(t_table *table)
{
	t_philo			**philos;
	unsigned int	i;

	philos = malloc(sizeof(t_philo) * table->nb_philo);
	if (!philos)
		return (NULL_ERROR);
	i = 0;
	while (i < table->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (NULL_ERROR);
		if (pthread_mutex_init(&philos[i]->m_meal, 0) != 0)
			return (NULL_ERROR);
		philos[i]->table = table;
		philos[i]->id = i;
		assign_forks(philos[i]);
		i++;
	}
	return (philos);
}

pthread_mutex_t	*init_forks(t_table *table)
{
	pthread_mutex_t	*forks;
	size_t			i;

	forks = malloc(sizeof(pthread_mutex_t) * table->nb_philo);
	if (!forks)
		return (NULL_ERROR);
	i = 0;
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], 0) != 0)
			return (NULL_ERROR);
		i++;
	}
	return (forks);
}

int	init_global_mutexes(t_table *table)
{
	table->m_forks = init_forks(table);
	if (!table->m_forks)
		return (FALSE);
	if (pthread_mutex_init(&table->m_simulation, 0) != 0)
		return (ERROR);
	if (pthread_mutex_init(&table->m_print, 0) != 0)
		return (ERROR);
	return (TRUE);
}

void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->nb_philo;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->table->nb_philo;
		philo->fork[1] = philo->id;
	}
}
