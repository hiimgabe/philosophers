/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:55:00 by gabe              #+#    #+#             */
/*   Updated: 2024/02/09 13:50:11 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_work_NME(int philo_n, int time_die, int time_eat, int time_sleep)
{
	printf("NME\nphilo_n %d\ntime_die %d\ntime_eat %d\ntime_sleep %d\n", philo_n, time_die, time_eat, time_sleep);
}

void	philo_work_ME(int philo_n, int time_die, int time_eat, int time_sleep, int must_eat)
{
	printf("ME\nphilo_n %d\ntime_die %d\ntime_eat %d\ntime_sleep %d\nmust_eat %d\n", philo_n, time_die, time_eat, time_sleep, must_eat);
}