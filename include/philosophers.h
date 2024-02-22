/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:51:45 by gabe              #+#    #+#             */
/*   Updated: 2024/02/22 13:42:35 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

/*
	* TABLE
	* 
	* ./philo 5 800 200 200 [5]
*/

typedef struct s_philo t_philo;

typedef	enum s_fork
{
	LEFT = 0,
	RIGHT = 1,
}	t_fork;

typedef struct s_table
{
	t_philo			*philos;
	long			philo_nb;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			meal_min;
	time_t			start;
	int				all_th;
	pthread_mutex_t	*forks;
	pthread_mutex_t	table_m;
	pthread_mutex_t	write_m;
	pthread_t		monitor;
}	t_table;

struct s_philo
{
	pthread_t		th;
	int				id;
	int				fork[2];
	int				nb_meals;
	time_t			last_meal;
	pthread_mutex_t	philo_m;
	t_table			*table;
};

// philosophers.c
void	philo_work_NME(int philo_n, int time_die, int time_eat, int time_sleep);
void	philo_work_ME(int philo_n, int time_die, int time_eat, int time_sleep, int must_eat);

// utils.c
int		error_exit(const char *error);
long	ft_atol(const char *str);
long	get_time(void);
void	thread_queue(time_t start);
void	philo_timer(t_table *table, time_t time);

// parsing.c
void	parse_input(char **argv);
bool	is_space(char c);
bool	is_digit(char c);

// init.c
t_table	*init_data(char **argv);

// routine.c
void	*routine(void *data);

// monitor.c
void	*monitor(void *data);

// forks.c
void	drop_forks(t_philo *philo);
void	grab_forks(t_philo *philo);

# endif