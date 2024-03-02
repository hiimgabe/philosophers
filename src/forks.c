/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:28:59 by gabe              #+#    #+#             */
/*   Updated: 2024/03/01 14:41:22 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	this still needs work

	the forks have already been assigned, we only need to access
	the correct ones with the data that we already have
	it should definitely be enough

	grabing the forks is the action of locking the forks mutexes so no other thread(philo) can grab it
	droping the forks is the opposite aka unlocking the forks mutexes so other philos can eat 
*/
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
/*
	DEBUG PRINTS
		printf(CYAN"%ld philo %d lock fork[%d] fork[%d]\n"NC, get_time(), philo->id, philo->fork[LEFT], philo->fork[RIGHT]);
		printf(CYAN"%ld philo %d lock fork[%d] fork[%d]\n"NC, get_time(), philo->id, philo->fork[RIGHT], philo->fork[LEFT]);
		printf(CYAN"%ld philo %d unlock fork[%d] fork[%d]\n"NC, get_time(), philo->id, philo->fork[RIGHT], philo->fork[LEFT]);
*/