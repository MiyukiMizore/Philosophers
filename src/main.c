/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:01:35 by mfusil            #+#    #+#             */
/*   Updated: 2022/10/21 16:37:11 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	*r;
	t_philo	*p;
	int		error;

	r = malloc(sizeof(t_rules));
	error = init_rules(argc, argv, r, p);
	if (check_error(error))
	{
		free (r);
		return (1);
	}
	if (start(r, argc) == 1)
		return (write(1, "thread error\n", 14));
	pthread_mutex_destroy(r->fork);
	free (r);
}
