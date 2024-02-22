/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabe <gabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 09:29:47 by gabe              #+#    #+#             */
/*   Updated: 2024/02/22 14:02:40 by gabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
	this will monitor if any philo died
	or if all philos are full
	if so, we stop the simulation
*/

void	*monitor(void *data)
{
	t_table	*table;

	table = (t_table *)data;
	printf("Monitoring started %ld\n", table->start);
	return (NULL);
}