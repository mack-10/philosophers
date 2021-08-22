/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:18:12 by sujeon            #+#    #+#             */
/*   Updated: 2021/08/22 14:02:43 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(int philo, char *status_str)
{
	long	time;

	time = calc_time(g_info.start_time);
	pthread_mutex_lock(&g_info.print);
	if (g_info.philo_die)
	{
		pthread_mutex_unlock(&g_info.print);
		return ;
	}
	printf("%ld %d %s\n", time, philo, status_str);
	pthread_mutex_unlock(&g_info.print);
}

/*	philo 왼 -> 오 */
void	eating(int philo, t_philo *status)
{
	if (philo == 1)
		pthread_mutex_lock(&g_info.fork[g_info.philo - 1]);
	else
		pthread_mutex_lock(&g_info.fork[philo - 2]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&g_info.fork[philo - 1]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(&status->mutex);
	print(philo, "is eating");
	g_info.last_eat[philo - 1] = calc_time(0);
	usleep(1000 * g_info.eat_time);
	status->cnt_eat++;
	pthread_mutex_unlock(&status->mutex);
	pthread_mutex_unlock(&g_info.fork[philo - 1]);
	if (philo == 1)
		pthread_mutex_unlock(&g_info.fork[g_info.philo - 1]);
	else
		pthread_mutex_unlock(&g_info.fork[philo - 2]);
}

void	sleeping(int philo)
{
	print(philo, "is sleeping");
	usleep(1000 * g_info.sleep_time);
}

void	thinking(int philo)
{
	print(philo, "is thinking");
	usleep(200);
}
