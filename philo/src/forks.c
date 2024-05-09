/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:28:59 by gabe              #+#    #+#             */
/*   Updated: 2024/03/02 21:31:46 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	grab_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork[LEFT]]);
		write_status(philo, FORK1);
		pthread_mutex_lock(&philo->table->forks[philo->fork[RIGHT]]);
		write_status(philo, FORK2);
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->fork[RIGHT]]);
		write_status(philo, FORK2);
		pthread_mutex_lock(&philo->table->forks[philo->fork[LEFT]]);
		write_status(philo, FORK1);
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->fork[LEFT]]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[RIGHT]]);
}
