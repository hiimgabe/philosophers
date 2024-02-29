/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:51:45 by gabe              #+#    #+#             */
/*   Updated: 2024/02/29 16:19:53 by gabe             ###   ########.fr       */
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

# define NC		"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

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

typedef enum s_status
{
	EAT,
	SLEEP,
	THINK,
	FORK1,
	FORK2,
	DEAD,
}	t_status;

typedef struct s_table
{
	t_philo			*philos;
	int				philo_nb;
	int				meal_min;
	bool			stop;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			start;
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
	time_t			nb_meals;
	time_t			last_meal;
	pthread_mutex_t	philo_m;
	t_table			*table;
};

// utils.c
int		error_exit(const char *error);
int		ft_atoi(const char *str);
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
bool	is_finished(t_table *table);

// forks.c
void	drop_forks(t_philo *philo);
void	grab_forks(t_philo *philo);

// status.c
void	write_status(t_philo *philo, t_status status);

// exit.c
void	finish_dinner(t_table *table);

# endif