/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 00:09:43 by sujeon            #+#    #+#             */
/*   Updated: 2021/08/22 04:12:17 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	calc_time(long sub_time)
{
	long			t;
	struct timeval	cur;

	gettimeofday(&cur, NULL);
	t = ((cur.tv_sec * 1000) + (cur.tv_usec / 1000)) - sub_time;
	return (t);
}
