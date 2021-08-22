/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:18:14 by sujeon            #+#    #+#             */
/*   Updated: 2021/08/22 04:38:34 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
**	HEADER
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define RED "\x1b[31m"
# define RE "\x1b[0m"
# define TRUE 1
# define FALSE 0

/*
**	STRUCT
*/

typedef struct s_info
{
	int				philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				philo_die;
	int				must_eat_end;
	long			start_time;
	long			*last_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
}t_info;

typedef struct s_philo
{
	int				cnt_eat;
	pthread_mutex_t	mutex;
}t_philo;

t_info	g_info;

/*
**	FUNCTION
*/

/* main.c */
int		error(char *s);

/* thread.c */
int		philosophers(void);

/* behavior.c */
void	eating(int philo, t_philo *status);
void	sleeping(int philo);
void	thinking(int philo);
void	print(int philo, char *status_str);

/* utils.c */
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	free_1(void **s);
long	calc_time(long sub_time);

#endif