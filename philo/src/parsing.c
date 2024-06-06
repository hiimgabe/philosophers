/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:03:53 by gabe              #+#    #+#             */
/*   Updated: 2024/06/06 13:24:26 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static int	check_digit(char *argv)
{
	int	i;

	i = -1;
	while (is_space(*argv))
		argv++;
	if (*argv == '+')
		argv++;
	else if (*argv == '-')
		return (error_exit("ERROR: Negative number.\n"));
	while (argv[++i])
		if (!is_digit(argv[i]))
			return (error_exit("ERROR: Non digit character.\n"));
	return (0);
}

static int	check_max_int(char *argv)
{
	int	len;
	int	nb;

	len = 0;
	nb = 0;
	while (is_space(*argv))
		argv++;
	if (*argv == '+')
		argv++;
	while (is_digit(*argv))
	{
		nb = (nb * 10) + (*argv++ - 48);
		len++;
	}
	if (len > 10 || nb > INT_MAX)
		return (error_exit("ERROR: Input bigger than INT_MAX.\n"));
	else if (nb == 0)
		return (error_exit("ERROR: Input can't be 0.\n"));
	return (0);
}

int	parse_input(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (check_digit(argv[i]))
			return (1);
		if (check_max_int(argv[i]))
			return (1);
	}
	return (0);
}

/*
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
		error_exit("Input bigger than INT_MAX.\n");
	return (number);
}
don't think i'll be using this

*/