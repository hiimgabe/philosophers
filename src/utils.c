/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:38:55 by gabe              #+#    #+#             */
/*   Updated: 2024/02/21 15:14:22 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_putstr(char const *str)
{
	while(*str)
		write(1 ,str++, 1);
}
void	error_exit(const char *error)
{
	ft_putstr(error);
	exit(EXIT_FAILURE);
}
long	get_time(void)
{
	struct timeval curr_time;

	gettimeofday(&curr_time, NULL);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));	
}
static long	ft_atol(const char *str)
{
	long	n;

	n = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	while(is_digit(*str))
		n = (n * 10) + (*str++ - 48);
	return (n);
}
