/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:17:56 by sujeon            #+#    #+#             */
/*   Updated: 2021/08/22 14:25:12 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *s)
{
	printf(RED "ERROR: ");
	printf("%s\n" RE, s);
	return (0);
}

static int	parsing(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (argv[i][0] == '-')
			return (0);
		if (argv[i][0] == '0')
			return (0);
		if (ft_strlen(argv[i]) >= 10
			&& ft_strncmp(argv[i], "2147483647", ft_strlen(argv[i])) > 0)
			return (0);
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (0);
	}
	return (1);
}

/*	1s = 1000 milliesecond
	1milliesecond = 1000 microsecond */
static int	set_info(char *argv[])
{
	int	i;

	memset(&g_info, 0, sizeof(t_info));
	g_info.philo = ft_atoi(argv[1]);
	g_info.die_time = ft_atoi(argv[2]);
	g_info.eat_time = ft_atoi(argv[3]);
	g_info.sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		g_info.must_eat = ft_atoi(argv[5]);
	g_info.start_time = calc_time(0);
	g_info.last_eat = (long *)malloc(g_info.philo * sizeof(long));
	g_info.fork = (pthread_mutex_t *)
		malloc(g_info.philo * sizeof(pthread_mutex_t));
	if (!g_info.fork || !g_info.last_eat)
		return (FALSE);
	i = -1;
	while (++i < g_info.philo)
		pthread_mutex_init(&g_info.fork[i], NULL);
	pthread_mutex_init(&g_info.print, NULL);
	return (TRUE);
}

static void	reset_all(void)
{
	int	i;

	i = -1;
	while (++i < g_info.philo)
		pthread_mutex_destroy(&g_info.fork[i]);
	pthread_mutex_destroy(&g_info.print);
	free_1((void **)&g_info.fork);
	free_1((void **)&g_info.last_eat);
}

int	main(int argc, char *argv[])
{
	if (!(argc == 5 || argc == 6))
		return (error("Number of arguments is not valid"));
	if (!parsing(argv) && argc > 1)
		return (error("Not valid argument"));
	if (!set_info(argv))
		return (FALSE);
	if (!philosophers())
		return (FALSE);
	reset_all();
	return (0);
}
