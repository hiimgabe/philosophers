/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:07:55 by gabe              #+#    #+#             */
/*   Updated: 2024/03/02 21:27:51 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_table	*table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].philo_m);
	}
	pthread_mutex_destroy(&table->table_m);
	pthread_mutex_destroy(&table->write_m);
}

int	join_threads(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nb)
	{
		if (pthread_join(table->philos[i].th, NULL))
			return (1);
	}
	if (table->philo_nb > 1)
	{
		pthread_join(table->monitor, NULL);
	}
	return (0);
}

void	finish_dinner(t_table *table)
{
	if (!table)
		return ;
	join_threads(table);
	destroy_mutexes(table);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table);
}
