/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfusil <mfusil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:46:30 by mfusil            #+#    #+#             */
/*   Updated: 2022/09/27 12:06:58 by mfusil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_error(int error)
{
	if (error == 1)
		return (write(1, "invalid number of arguments\n", 28));
	if (error == 2)
		return (write(2, "error in struct rules\n", 22));
	if (error == 3)
		return (write(2, "error argument meal\n", 20));
	return (error);
}
