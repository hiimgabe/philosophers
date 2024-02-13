/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:51:45 by gabe              #+#    #+#             */
/*   Updated: 2024/02/13 17:56:47 by gabe             ###   ########.fr       */
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

typedef struct s_table
{
	long	philo_nb;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meal_min;
} t_table;

typedef struct s_philo
{
	pthread_t		philosopher;
	struct s_philo	*next_philo;
	struct s_philo	*prev_philo;
	bool			fork;
	int				state;
	int				pos;
} t_philo;

// philosophers.c
void	philo_work_NME(int philo_n, int time_die, int time_eat, int time_sleep);
void	philo_work_ME(int philo_n, int time_die, int time_eat, int time_sleep, int must_eat);

// utils.c
void	error_exit(const char *error);

// parsing.c
void	parse_input(t_table *table, char **argv);

# endif