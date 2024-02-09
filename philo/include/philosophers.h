/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:51:45 by gabe              #+#    #+#             */
/*   Updated: 2024/02/09 16:33:22 by gabe             ###   ########.fr       */
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
int		ft_atoi(const char *str);

# endif