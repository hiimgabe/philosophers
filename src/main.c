/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:52:30 by gabe              #+#    #+#             */
/*   Updated: 2024/02/23 14:59:15gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	* if (argc == 5 || argc == 6)
	*
	* 1) parse the arguments to the table
*/

static bool	start_routine(t_table *table)
{
	int	i;

	table->start = get_time() + (table->philo_nb * 10);									// if we do get_time() + (table->philo_nb * 10) it seems
	i = -1;
	while (++i < table->philo_nb)														// no idea why but this is something to experiemnt more with
	{
		if (pthread_create(&table->philos[i].th, NULL, routine, &table->philos[i]))
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
		return(error_exit("ERROR: Wrong input arguments.\n"));
	parse_input(argv);
	table = init_data(argv);
	if (!table)
		return (error_exit("ERROR: Failed to init data.\n"));
	if (!start_routine(table))
		return (error_exit("ERROR: Failed to start routine.\n"));
	finish_dinner(table);
	return (0);
}
/*																						USEFUL PRINTING INFO (maybe)
		int	i = -1;
		while (++i < table->philo_nb)
		{
			printf("Philo : %d can use fork[%d] & fork[%d]\n", table->philos[i].id, table->philos[i].fork[LEFT], table->philos[i].fork[RIGHT]);
		}
		printf("The %ld Philos will have %ld time to eat, %ld time to sleep and they die if %ld time has passed before they eat\n", table->philo_nb, table->time_to_eat, table->time_to_sleep, table->time_to_die);
		if (argv[5])
			printf("Philos will be full after eating %ld times\n", table->meal_min);// 4) clean the program
*/