/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:38:07 by mfusil            #+#    #+#             */
/*   Updated: 2022/10/28 11:38:11 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

//----------------struct----------------//

typedef struct philo
{
	int				number_of_meal_eating;
	int				id;
	long long		last_meal;
	int				fork_left_id;
	int				fork_right_id;
	pthread_t		thread;
	struct rules	*rules;
}	t_philo;

typedef struct rules
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meal;
	int				all_meal;
	int				died;
	long long		time_elapsed;
	long long		first_time_elapsed;
	pthread_mutex_t	fork[200];
	pthread_t		eat_checker;
	t_philo			p[200];
}	t_rules;

//----------------utils----------------//
int			is_digit(int c);
int			ft_atoi(const char *str);
int			*convert_str(int argc, char **argv);
long long	time_spent(void);
void		time_to_do(long long time, t_rules *r);
long long	time_diff(long long past, long long pres);
void		ft_sleep(int sleep_time);

//----------------error----------------//
int			check_error(int error);

//----------------init----------------//
int			init_rules(int argc, char **argv, t_rules *r, t_philo *p);
int			init_mutex(t_rules *r, t_philo *p);
int			init_philo(t_rules *r, t_philo *p);

//----------------philosophers----------------//
int			main(int argc, char **argv);
int			start(t_rules *r, int argc);
void		death_checker(t_rules *r);

#endif