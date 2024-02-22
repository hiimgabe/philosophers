/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:03:53 by gabe              #+#    #+#             */
/*   Updated: 2024/02/22 13:55:08 by gabe             ###   ########.fr       */
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
static void	check_digit(char *argv)
{
	while (is_space(*argv))
		argv++;
	if (*argv == '+')
		argv++;
	else if (*argv == '-')
		error_exit("ERROR: Negative number.\n");
	if (!is_digit(*argv))
		error_exit("ERROR: Non digit argument.\n");
}

static void	check_max_int(char *argv)
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
		error_exit("ERROR: Input bigger than INT_MAX.\n");
	else if (nb == 0)
		error_exit("ERROR: Input can't be 0.\n");
}
void	parse_input(char **argv)
{
	int	i;

	i = 0;
	while(argv[++i])
	{
		check_digit(argv[i]);
		check_max_int(argv[i]);															// this seems to be okay for now
	}
}
