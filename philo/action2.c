/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:11:03 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/24 12:31:35 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(int id, int status, t_info *info)
{
	long long	t_cur;

	t_cur = set_time() - (info->t_start);
	pthread_mutex_lock(&(info->l_print));
	if (status == FORK)
		printf("%lldms %d has taken a fork\n", t_cur, id + 1);
	else if (status == EAT)
		printf("%lldms %d is eating\n", t_cur, id + 1);
	else if (status == SLEEP)
		printf("%lldms %d is sleeping\n", t_cur, id + 1);
	else if (status == THINK)
		printf("%lldms %d is thinking\n", t_cur, id + 1);
	else if (status == DIE)
		printf("%lldms %d died\n", t_cur, id + 1);
	pthread_mutex_unlock(&(info->l_print));
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

int	philo_check(t_info *info, t_philo *philo, int full)
{
	long long	t_cur;

	if (full)
	{
		if (info->c_full >= info->n_philo)
			return (1);
		else
			return (0);
	}
	t_cur = set_time();
	if (info->is_dead)
		return (1);
	if (info->t_die < t_cur - philo->t_last_eat)
	{
		info->is_dead = 1;
		philo_print(philo->id, DIE, info);
		return (1);
	}
	return (0);
}
