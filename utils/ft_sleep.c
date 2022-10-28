/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:34:58 by mfusil            #+#    #+#             */
/*   Updated: 2022/10/28 11:51:10 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_sleep(int sleep_time)
{
	long long	start_sleep_time;

	start_sleep_time = time_spent();
	usleep(sleep_time * 0.90);
	while (time_spent() < sleep_time + start_sleep_time)
		usleep(5);
}
