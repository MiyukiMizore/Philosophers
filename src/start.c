/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:37:09 by mfusil            #+#    #+#             */
/*   Updated: 2022/10/28 12:34:12 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eating_checker(void *rules)
{
	t_rules	*r;
	int		i;

	i = 0;
	r = (t_rules *)rules;
	while (!r->all_meal && !r->died)
	{
		while (i < r->number_of_philosophers
			&& (r->p[i].number_of_meal_eating == r->number_of_meal))
			i++;
		if (i == r->number_of_philosophers)
			r->all_meal = 1;
		usleep (10);
	}
	return (NULL);
}

void	start_eating(t_rules *r, t_philo *p)
{
	pthread_mutex_lock(&(r->fork[p->fork_left_id]));
	printf("%lli philo %d has taken left fork\n",
		time_spent() - r->first_time_elapsed, p->id);
	pthread_mutex_lock(&(r->fork[p->fork_right_id]));
	printf("%lli philo %d has taken right fork\n",
		time_spent() - r->first_time_elapsed, p->id);
	if (r->died)
		return ;
	printf("%lli philo %d is eating\n",
		time_spent() - r->first_time_elapsed, p->id);
	p->last_meal = time_spent();
	ft_sleep(r->time_to_eat / 1000);
	time_to_do((long long)time, r);
	p->number_of_meal_eating++;
	pthread_mutex_unlock(&(r->fork[p->fork_left_id]));
	pthread_mutex_unlock(&(r->fork[p->fork_right_id]));
}

void	*mon_reuf(void *s_philo)
{
	t_philo	*p;
	t_rules	*r;
	int		i;

	i = 0;
	p = (t_philo *)s_philo;
	r = p->rules;
	if (p->id % 2)
		usleep (50);
	while (r->died == 0 && r->all_meal == 0)
	{
		start_eating(r, p);
		if (r->died)
			break ;
		printf("%lli philo %d is sleeping\n",
			time_spent() - r->first_time_elapsed, p->id);
		ft_sleep(r->time_to_sleep / 1000);
		if (r->died == 0)
			printf("%lli philo %d is thinking\n",
				time_spent() - r->first_time_elapsed, p->id);
		if (p->number_of_meal_eating >= r->number_of_meal
			&& r->number_of_meal != -1)
			break ;
	}
	return (NULL);
}

int	start(t_rules *r, int argc)
{
	int		i;
	t_philo	*p;

	i = 0;
	p = r->p;
	r->first_time_elapsed = time_spent();
	while (i < r->number_of_philosophers)
	{
		if (pthread_create(&(p[i].thread), NULL, mon_reuf, &(p[i])))
			return (1);
		pthread_detach(p[i].thread);
		p[i].last_meal = time_spent();
		i++;
	}
	if (argc == 6)
	{
		pthread_create(&(r->eat_checker), NULL, eating_checker, r);
		pthread_detach(r->eat_checker);
	}
	death_checker(r);
	return (0);
}
