/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 12:00:13 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/27 10:12:48 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '+')
				return (0);
			else if (av[i][j] == '+')
			{
				if (av[i][j + 1] && av[i][j + 1] == '+')
					return (0);
				if (av[i][j - 1] && (av[i][j - 1] > 47 && av[i][j - 1] < 58))
					return (0);
				continue ;
			}
		}
	}
	return (1);
}

int	char_to_int(const char *s)
{
	long long	res;

	res = 0;
	if (*s == '-')
		return (-1);
	while (*s)
	{
		if (res > INT_MAX)
			return (-1);
		else if (*s >= '0' && *s <= '9')
			res = res * 10 + (*s - '0');
		s++;
	}
	return (res);
}

long long	set_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	free_all(t_info *info, t_philo **philo)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
		pthread_mutex_destroy(&info->fork[i]);
	i = -1;
	if (info->n_philo == 1)
		pthread_detach((*philo)[0].thread);
	else
		while (++i < info->n_philo)
			pthread_join((*philo)[i].thread, NULL);
	pthread_mutex_destroy(&info->m_print);
	pthread_mutex_destroy(&info->m_dead);
	pthread_mutex_destroy(&info->m_last_eat);
	pthread_mutex_destroy(&info->m_c_full);
	free(info->fork);
	free(*philo);
}
