/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:04:51 by gabe              #+#    #+#             */
/*   Updated: 2024/02/21 16:20:52 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	init the philosophers threads
	init forks
	init mutexes
*/

static t_philo	init_philos(t_table *table)
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
		assign_forks(philo[i].fork) // CONTINUE HERE
	}	
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
	if (argv[5])
		table->meal_min = ft_atol(argv[5]);
	else
		table->meal_min = -1;
	table->philos = init_philos(table);
}