/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:06:50 by mfusil            #+#    #+#             */
/*   Updated: 2022/10/28 12:31:09 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	death_checker(t_rules *r)
{
	int	i;

	while (!r->died && !r->all_meal)
	{
		i = 0;
		while (i < r->number_of_philosophers && r->all_meal == 0)
		{	
			if (time_diff(r->p[i].last_meal, time_spent()) >= r->time_to_die)
			{
				printf("%lli philo %d is died\n",
					time_spent() - r->first_time_elapsed, r->p[i].id);
				r->died = 1;
				break ;
			}
			i++;
		}
		usleep(50);
	}
	return ;
}
