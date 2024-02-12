/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:38:55 by gabe              #+#    #+#             */
/*   Updated: 2024/02/12 17:09:04 by gabe             ###   ########.fr       */
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