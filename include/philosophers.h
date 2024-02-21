/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:51:45 by gabe              #+#    #+#             */
/*   Updated: 2024/02/21 16:14:45 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "pthread.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

/*
	* TABLE
	* 
	* ./philo 5 800 200 200 [5]
*/

typedef	enum s_fork
{
	LEFT = 0,
	RIGHT = 1,
}	t_fork;

typedef struct s_table
{
	t_philo			*philos;
	long			philo_nb;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meal_min;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				fork[2];
	int				nb_meals;
	time_t			last_meal;
	pthread_mutex_t	philo_m;
	t_table			*table;
}	t_philo;

// philosophers.c
void	philo_work_NME(int philo_n, int time_die, int time_eat, int time_sleep);
void	philo_work_ME(int philo_n, int time_die, int time_eat, int time_sleep, int must_eat);

// utils.c
void	error_exit(const char *error);
bool	is_space(char c);
bool	is_digit(char c);

// parsing.c
void	parse_input(char **argv);

# endif