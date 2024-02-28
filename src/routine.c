/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:27:57 by gabe              #+#    #+#             */
/*   Updated: 2024/02/28 15:19:54 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat_sleep(t_philo *philo)
{
	grab_forks(philo);
	pthread_mutex_lock(&philo->philo_m);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->philo_m);
	write_status(philo, EAT);
	philo_timer(philo->table, philo->table->time_to_eat);
	pthread_mutex_lock(&philo->philo_m);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->philo_m);
	drop_forks(philo);
	write_status(philo, SLEEP);
	philo_timer(philo->table, philo->table->time_to_sleep);
}

void	think(t_philo *philo)
{
	time_t	thinking_time;

	pthread_mutex_lock(&philo->philo_m);
	thinking_time = (philo->table->time_to_die - philo->table->time_to_eat - philo->table->time_to_sleep) / 2;
	pthread_mutex_unlock(&philo->philo_m);
	if (thinking_time < 0)
		thinking_time = 0;
	if (thinking_time > 600)
		thinking_time = 200;
	write_status(philo, THINK);
	philo_timer(philo->table, thinking_time);
}

	/*																	void	lonely_philo(t_philo *philo)
																		{
																			manage simulation if only 1 philo present
																			he can't eat because he needs two forks
																			so he probably just thinks sleeps and dies
																		}
	*/

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	thread_queue(philo->table);
	pthread_mutex_lock(&philo->philo_m);								//	experiment if we really need to update last_meal a second time
	philo->last_meal = philo->table->start;								//	or if it is enough to update it on start_routine()
	pthread_mutex_unlock(&philo->philo_m);								//	for now it seems to need the redundancy (idk why)																	lonely_philo(philo) goes in here <----------
	if (philo->id % 2)
		think(philo);
	while(!is_finished(philo->table))
	{
		eat_sleep(philo);
		think(philo);
		printf("Time	:	%ld", get_time() - philo->table->start);
	}
	return (NULL);
}