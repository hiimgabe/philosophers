/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:28:59 by gabe              #+#    #+#             */
/*   Updated: 2024/02/22 14:01:45 by gabe             ###   ########.fr       */
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
	if (philo->id == philo->table->philo_nb)										//	this is probably wrong
	{
		pthread_mutex_lock(&philo->table->forks[philo->id - 1]);
		//																				write_status FORK1
		pthread_mutex_lock(&philo->table->forks[0]);
		//																				write_status FORK2
	}
	else
	{
		pthread_mutex_lock(&philo->table->forks[philo->id - 1]);
		//																				write_status FORK1
		pthread_mutex_lock(&philo->table->forks[philo->id]);
		//																				write_status FORK2
	}
}

void	drop_forks(t_philo *philo)
{
	if (philo->id == philo->table->philo_nb)										//	this is wrong and over complicated
	{
		pthread_mutex_unlock(&philo->table->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->table->forks[0]);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->table->forks[philo->id]);
	}
}