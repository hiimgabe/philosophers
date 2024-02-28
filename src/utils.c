/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:38:55 by gabe              #+#    #+#             */
/*   Updated: 2024/02/28 15:23:38 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_exit(const char *error)
{
	printf("%s\n", error);
	return (EXIT_FAILURE);
}
long	get_time(void)
{
	struct timeval curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));	
}
int	ft_atoi(const char *str)
{
	int	n;

	n = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	while(is_digit(*str))
		n = (n * 10) + (*str++ - 48);
	return (n);
}

void	thread_queue(t_table *table)
{
	while (table->th_nb != table->philo_nb)
		continue;
}
void	philo_timer(t_table *table, time_t time)
{
	time_t	stop;

	stop = get_time() + time;
	while (get_time() < stop)
	{
		pthread_mutex_lock(&table->write_m);
		printf("I am counting the time");
		pthread_mutex_unlock(&table->write_m);
		if (is_finished(table))
			break;
		usleep(100);
	}
}