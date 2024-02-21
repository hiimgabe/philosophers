/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:52:30 by gabe              #+#    #+#             */
/*   Updated: 2024/02/21 15:07:53 by gabe             ###   ########.fr       */
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
	
	if (argc == 5 || argc == 6)
	{
		// 1) parse input
		parse_input(argv);
		// 2) init data
		table = init_data(argv);
		// 3) put philos to work

		// 4) clean the program
	}
	else
		error_exit("Invalid arguments.\nCorrect example: ./philo 5 800 200 200"); // Return error. Invalid arguments.
	return (0);
}