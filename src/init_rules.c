/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:59:49 by mfusil            #+#    #+#             */
/*   Updated: 2022/10/21 14:04:41 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	init_rules(int argc, char **argv, t_rules *r, t_philo *p)
{
	int	*tab;
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		return (1);
	r->number_of_philosophers = ft_atoi(argv[1]);
	r->time_to_die = ft_atoi(argv[2]);
	r->time_to_eat = ft_atoi(argv[3]) * 1000;
	r->time_to_sleep = ft_atoi(argv[4]) * 1000;
	r->all_meal = 0;
	r->died = 0;
	if (r->number_of_philosophers <= 0 || r->time_to_die <= 0
		|| r->time_to_eat <= 0 || r->time_to_sleep <= 0
		|| r->number_of_philosophers > 200)
		return (2);
	if (argc == 6)
	{
		r->number_of_meal = ft_atoi(argv[5]);
		if (r->number_of_meal <= 0)
			return (3);
	}
	else
		r->number_of_meal = -1;
	return (init_mutex(r, p));
}

int	init_mutex(t_rules *r, t_philo *p)
{
	int	i;

	i = r->number_of_philosophers;
	while (i--)
	{
		if (pthread_mutex_init(&(r->fork[i]), NULL))
			return (4);
	}
	return (init_philo(r, p));
}

int	init_philo(t_rules *r, t_philo *p)
{
	int	i;

	i = r->number_of_philosophers;
	while (i--)
	{
		r->p[i].id = i;
		r->p[i].fork_left_id = i;
		r->p[i].fork_right_id = i + 1 % r->number_of_philosophers;
		r->p[i].number_of_meal_eating = 0;
		r->p[i].rules = r;
	}
	return (0);
}
