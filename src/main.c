/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:52:30 by gabe              #+#    #+#             */
/*   Updated: 2024/02/22 08:49:52 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	* if (argc == 5 || argc == 6)
	*
	* 1) parse the arguments to the table
*/

int	main(int argc, char **argv)
{
	t_table	*table;
	int	i = -1;
	
	if (argc == 5 || argc == 6)
	{
		// 1) parse input
		parse_input(argv);
		// 2) init data
		table = init_data(argv);
		// 3) put philos to work
		while (++i < table->philo_nb)
		{
			printf("Philo : %d can use fork[%d] & fork[%d]\n", table->philos[i].id, table->philos[i].fork[LEFT], table->philos[i].fork[RIGHT]);
		}
		printf("The %ld Philos will have %ld time to eat, %ld time to sleep and they die if %ld time has passed before they eat\n", table->philo_nb, table->time_to_eat, table->time_to_sleep, table->time_to_die);
		if (argv[5])
			printf("Philos will be full after eating %ld times\n", table->meal_min);// 4) clean the program
	}
	else
		error_exit("Invalid arguments.\nCorrect example: ./philo 5 800 200 200"); // Return error. Invalid arguments.
	return (0);
}