/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:52:30 by gabe              #+#    #+#             */
/*   Updated: 2024/03/02 21:34:48 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	start_routine(t_table *table)
{
	int	i;

	table->start = get_time() + (table->philo_nb * 10);
	i = -1;
	while (++i < table->philo_nb)
	{
		if (pthread_create(&table->philos[i].th, NULL,
				routine, &table->philos[i]))
			return (false);
		pthread_mutex_lock(&table->philos[i].philo_m);
		table->philos[i].last_meal = table->start;
		pthread_mutex_unlock(&table->philos[i].philo_m);
	}
	if (table->philo_nb > 1)
		if (pthread_create(&table->monitor, NULL, monitor, table))
			return (false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc != 5 && argc != 6)
		return (error_exit("ERROR: Wrong input arguments.\n"));
	parse_input(argv);
	table = init_data(argv);
	if (!table)
		return (error_exit("ERROR: Failed to init data.\n"));
	if (!start_routine(table))
		return (error_exit("ERROR: Failed to start routine.\n"));
	finish_dinner(table);
	return (0);
}
