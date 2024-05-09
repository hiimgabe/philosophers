/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamoreir <gamoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:24:52 by gabe              #+#    #+#             */
/*   Updated: 2024/05/08 16:51:13 by gamoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	write_status(t_philo *philo, t_status status)
{
	char		*msg;
	long int	curr_time;

	msg = NULL;
	if (is_finished(philo->table))
		return ;
	if (status == EAT)
		msg = "is eating";
	else if (status == SLEEP)
		msg = "is sleeping";
	else if (status == THINK)
		msg = "is thinking";
	else if (status == FORK1 || status == FORK2)
		msg = "took a fork";
	else if (status == DEAD)
		msg = "died";
	pthread_mutex_lock(&philo->table->write_m);
	curr_time = get_time();
	printf("%ld\t\t", curr_time - philo->table->start);
	printf("%d %s.\n", philo->id, msg);
	pthread_mutex_unlock(&philo->table->write_m);
}
