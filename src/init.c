/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:04:51 by gabe              #+#    #+#             */
/*   Updated: 2024/02/23 16:29:59 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	this seems to be okay for now

	we initialiaze the mutexes and allocate memory necessary for our program to work

*/

static pthread_mutex_t	*init_forks(t_table *table)
{
	int	i;
	pthread_mutex_t	*forks;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * table->philo_nb);
	while (++i < table->philo_nb)
	{
		if (pthread_mutex_init(&forks[i], NULL))
			return (NULL);
	}
	return (forks);
}

static void	assign_forks(t_philo *philo, int index)
{
	philo->fork[LEFT] = philo->id - 1;
	if (philo->table->philo_nb - 1 == index)
		philo->fork[RIGHT] = 0;
	else
		philo->fork[RIGHT] = philo->id;
}

static int	init_mutexes(t_table *table)
{
	table->forks = init_forks(table);
	if (!table->forks)
		return (error_exit("ERROR: Failed to init fork mutexes.\n"));
	if (pthread_mutex_init(&table->table_m, NULL))
		return (error_exit("ERROR: Failed to init table mutex.\n"));
	if (pthread_mutex_init(&table->write_m, NULL))
		return (error_exit("ERROR: Failed to init write mutex.\n"));
	return (0);
}

static t_philo	*init_philos(t_table *table)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_nb);
	if (!philos)
		return (NULL);
	while (++i < table->philo_nb)
	{
		if (pthread_mutex_init(&philos[i].philo_m, NULL))
		{
			error_exit("Failed to init philo mutex.\n");
			return (NULL);
		}
		philos[i].id = i + 1;
		philos[i].nb_meals = 0;
		philos[i].last_meal = 0;
		philos[i].table = table;
		assign_forks(&philos[i], i);
	}
	return (philos);
}

t_table	*init_data(char **argv)
{
	t_table *table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo_nb = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	table->stop = false;
	if (argv[5])
		table->meal_min = ft_atol(argv[5]);
	else
		table->meal_min = -1;
	if (init_mutexes(table))
		return (NULL);
	table->philos = init_philos(table);
	if (!table->philos)
		return (NULL);
	return (table);
}
