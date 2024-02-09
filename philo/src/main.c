/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:52:30 by gabe              #+#    #+#             */
/*   Updated: 2024/02/09 17:16:27 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	struct timeval current_time;
	int	philo_nb;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;

	philo_nb = 0;
	time_die = 0;
	time_eat = 0;
	time_sleep = 0;
	must_eat= 0;
	gettimeofday(&current_time, NULL);
	/*if (argc == 5 || argc == 6)
	{
		philo_nb = ft_atoi(argv[1]);
		time_die = ft_atoi(argv[2]);
		time_eat = ft_atoi(argv[3]);
		time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			must_eat = ft_atoi(argv[5]);
	}
	else
		return (write(2, "Invalid arguments.\n", 19));*/
	//if (philo_nb > 0)
	//	init_philosophers(philo_nb);
	printf("1\nseconds : %ld\nmicro seconds : %ld\nmiliseconds : %ld\n", current_time.tv_sec, (current_time.tv_usec / 1000), (current_time.tv_sec * 1000));
	return (0);
}