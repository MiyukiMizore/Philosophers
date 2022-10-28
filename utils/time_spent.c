/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_spent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:08:04 by mfusil            #+#    #+#             */
/*   Updated: 2022/10/28 11:42:29 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	time_spent(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void	time_to_do(long long time, t_rules *r)
{
	long long	i;

	i = time_spent();
	while (r->died && r->all_meal)
	{
		if (time_diff(i, time_spent()) >= time)
			break ;
		usleep (50);
	}
}
