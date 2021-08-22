/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 01:57:04 by sujeon            #+#    #+#             */
/*   Updated: 2021/08/21 00:10:01 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;

	idx = 0;
	while (n-- && (s1[idx] || s2[idx]))
	{
		if (s1[idx] != s2[idx])
			return (s1[idx] - s2[idx]);
		idx++;
	}
	if (s1[idx] || s2[idx])
		return (s1[idx] - s2[idx]);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	idx;
	int	n;
	int	sign;

	idx = 0;
	n = 0;
	sign = 1;
	while (str[idx] == ' ' || str[idx] == '\n' || str[idx] == '\t'
		|| str[idx] == '\r' || str[idx] == '\v' || str[idx] == '\f')
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		n = (10 * n) + (str[idx] - '0');
		idx++;
	}
	return (sign * n);
}

void	free_1(void **s)
{
	free(*s);
	*s = NULL;
}
