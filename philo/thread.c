/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:30:17 by sujeon            #+#    #+#             */
/*   Updated: 2021/08/22 14:22:27 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*if_die(int philo, pthread_mutex_t mutex)
{
	int	i;

	print(philo, "died");
	g_info.philo_die = TRUE;
	i = -1;
	while (++i < g_info.philo)
		pthread_mutex_unlock(&g_info.fork[i]);
	pthread_mutex_unlock(&mutex);
	pthread_mutex_destroy(&mutex);
	return (NULL);
}

static void	*monitor(void *arg)
{
	int				philo;
	pthread_mutex_t	mutex;

	philo = *(int *)arg;
	pthread_mutex_init(&mutex, NULL);
	while (g_info.philo_die == FALSE)
	{
		pthread_mutex_lock(&mutex);
		if (g_info.must_eat_end == g_info.philo)
		{	
			pthread_mutex_unlock(&mutex);
			return (NULL);
		}
		if (calc_time(g_info.last_eat[philo - 1]) > g_info.die_time)
			return (if_die(philo, mutex));
		pthread_mutex_unlock(&mutex);
		usleep(1000);
	}
	return (NULL);
}

static void	*f_thread(void *arg)
{
	int			philo;
	t_philo		status;
	pthread_t	thread;

	philo = *(int *)arg;
	g_info.last_eat[philo - 1] = calc_time(0);
	memset(&status, 0, sizeof(t_philo));
	pthread_mutex_init(&status.mutex, NULL);
	if (pthread_create(&thread, NULL, monitor, arg) != 0)
		return (NULL);
	pthread_detach(thread);
	while (g_info.philo_die == FALSE)
	{
		eating(philo, &status);
		if (g_info.must_eat > 0 && status.cnt_eat == g_info.must_eat)
			return (NULL);
		sleeping(philo);
		thinking(philo);
	}
	if (g_info.philo_die == TRUE)
		pthread_mutex_destroy(&status.mutex);
	return (NULL);
}

int	philosophers(void)
{
	int			i;
	int			*philo;
	pthread_t	*thread;

	thread = (pthread_t *)malloc(g_info.philo * sizeof(pthread_t));
	philo = (int *)malloc(g_info.philo * sizeof(int));
	if (!thread || !philo)
		return (0);
	i = -1;
	while (++i < g_info.philo)
	{
		philo[i] = i + 1;
		if (pthread_create(&thread[i], NULL, f_thread, &philo[i]) != 0)
			return (error("In pthread_create"));
		usleep(50);
	}
	i = -1;
	while (++i < g_info.philo)
		pthread_join(thread[i], NULL);
	free_1((void **)&thread);
	free_1((void **)&philo);
	return (1);
}
