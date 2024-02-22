/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:38:55 by gabe              #+#    #+#             */
/*   Updated: 2024/02/22 08:31:20 by gabe             ###   ########.fr       */
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
long	ft_atol(const char *str)
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
