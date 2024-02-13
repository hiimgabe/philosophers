/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:03:53 by gabe              #+#    #+#             */
/*   Updated: 2024/02/13 17:57:09 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static inline bool is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
/*
	* verify if input is only positive numbers
	* and isn't bigger than INT_MAX
	* valid input: "42" "  234" "	 +45*%^"
*/

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		++str;
	if (*str == '+')
		str++;
	else if (*str == '-')
		error_exit("Input is a negative number.\n");
	if (!is_digit(*str))
		error_exit("Input isn't a digit.\n");
	number = str;
	while (is_digit(*str++))
		len++;
	if(len > 10)
		error_exit("Input bigger than INT_MAX.");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	n;

	n = 0;
	str = valid_input(str);
	while (is_digit(*str))
		n = (n * 10) + (*str++ - 48);
	if (n > INT_MAX)
		error_exit("Input bigger than INT_MAX");
	return (n);
}

void	parse_input(t_table *table, char **argv)
{
	table->philo_nb = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->meal_min = ft_atol(argv[5]);
	else
		table->meal_min = -1;
}