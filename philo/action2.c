/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:11:03 by yeongele          #+#    #+#             */
/*   Updated: 2023/04/08 14:36:12 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(int id, int status, t_info *info)
{
	long long	t_cur;

	pthread_mutex_lock(&(info->m_dead));
	if (!info->is_dead)
	{
		pthread_mutex_lock(&(info->m_print));
		t_cur = set_time() - info->t_start;
		if (status == FORK)
			printf("%lld %d has taken a fork\n", t_cur, id + 1);
		else if (status == EAT)
			printf("%lld %d is eating\n", t_cur, id + 1);
		else if (status == SLEEP)
			printf("%lld %d is sleeping\n", t_cur, id + 1);
		else if (status == THINK)
			printf("%lld %d is thinking\n", t_cur, id + 1);
		pthread_mutex_unlock(&(info->m_print));
	}
	pthread_mutex_unlock(&(info->m_dead));
}

void	philo_wait(long long t)
{
	long long	t_cur;
	long long	t_start;

	t_start = set_time();
	while (1)
	{
		t_cur = set_time();
		if (t_cur - t_start >= t)
			break ;
		usleep(100);
	}
}

int	philo_check_full(t_info *info)
{
	pthread_mutex_lock(&(info->m_c_full));
	if (info->c_full >= info->n_philo)
	{
		pthread_mutex_unlock(&(info->m_c_full));
		return (1);
	}
	pthread_mutex_unlock(&(info->m_c_full));
	return (0);
}

int	philo_check_death(t_info *info, t_philo *philo)
{
	long long	t_cur;

	t_cur = set_time();
	pthread_mutex_lock(&(info->m_dead));
	if (info->is_dead)
	{
		pthread_mutex_unlock(&(info->m_dead));
		return (1);
	}
	pthread_mutex_lock(&(info->m_last_eat));
	if (info->t_die < t_cur - philo->t_last_eat)
	{
		info->is_dead = 1;
		pthread_mutex_unlock(&(info->m_dead));
		pthread_mutex_unlock(&(info->m_last_eat));
		printf("%lld %d died\n", t_cur - info->t_start, philo->id + 1);
		return (1);
	}
	pthread_mutex_unlock(&(info->m_last_eat));
	pthread_mutex_unlock(&(info->m_dead));
	return (0);
}
