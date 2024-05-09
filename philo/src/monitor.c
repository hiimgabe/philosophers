/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:29:47 by gabe              #+#    #+#             */
/*   Updated: 2024/03/02 21:39:10 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	stop_everything(t_table *table, bool flag)
{
	pthread_mutex_lock(&table->table_m);
	table->stop = flag;
	pthread_mutex_unlock(&table->table_m);
}

static bool	is_dead(t_philo *philo)
{
	time_t	elapsed;

	elapsed = get_time() - philo->last_meal;
	if (elapsed > philo->table->time_to_die)
	{
		write_status(philo, DEAD);
		stop_everything(philo->table, true);
		pthread_mutex_unlock(&philo->philo_m);
		return (true);
	}
	return (false);
}

static bool	end_routine(t_table *table)
{
	int		i;
	bool	philos_statisfied;

	i = -1;
	philos_statisfied = true;
	while (++i < table->philo_nb)
	{
		pthread_mutex_lock(&table->philos[i].philo_m);
		if (is_dead(&table->philos[i]))
		{
			stop_everything(table, true);
			return (true);
		}
		if (table->meal_min != -1
			&& table->philos[i].nb_meals < table->meal_min)
			philos_statisfied = false;
		pthread_mutex_unlock(&table->philos[i].philo_m);
	}
	if (table->meal_min != -1 && philos_statisfied)
	{
		stop_everything(table, true);
		return (true);
	}
	return (false);
}

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	if (table->meal_min == 0)
		return (NULL);
	thread_queue(table->start);
	while (!end_routine(table))
		usleep(1000);
	return (NULL);
}

bool	is_finished(t_table *table)
{
	bool	finish;

	finish = false;
	pthread_mutex_lock(&table->table_m);
	if (table->stop)
		finish = true;
	pthread_mutex_unlock(&table->table_m);
	return (finish);
}
