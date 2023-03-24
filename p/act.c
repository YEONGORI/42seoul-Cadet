/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:12:24 by jihyukim          #+#    #+#             */
/*   Updated: 2022/09/08 15:19:30 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork[philo->left]);
	prints(info, philo->id, FORK);
	pthread_mutex_lock(&info->fork[philo->right]);
	prints(info, philo->id, FORK);
	prints(info, philo->id, EAT);
	pthread_mutex_lock(&info->check_last_eat);
	philo->t_last_eat = get_time();
	pthread_mutex_unlock(&info->check_last_eat);
	psleep(info->t_eat);
	philo->n_eat += 1;
	pthread_mutex_unlock(&(info->fork[philo->right]));
	pthread_mutex_unlock(&(info->fork[philo->left]));
	philo->status = SLEEP;
}

void	philo_sleep(t_info *info, t_philo *philo)
{
	prints(info, philo->id, SLEEP);
	psleep(info->t_sleep);
	philo->status = THINK;
}

void	philo_think(t_info *info, t_philo *philo)
{
	prints(info, philo->id, THINK);
	philo->status = EAT;
}

void	add_full(t_info *info, int n_eat)
{
	if (n_eat == info->n_must_eat)
	{
		pthread_mutex_lock(&(info->check_full));
		info->n_full_philo += 1;
		pthread_mutex_unlock(&(info->check_full));
	}
}

void	*philo_act(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	if (philo->id % 2 == 1)
		usleep(100);
	while (1)
	{
		if ((info->n_must_eat > 0 && philo->n_eat >= info->n_must_eat)
			|| is_dead(info, philo))
			break ;
		if (philo->status == EAT)
			philo_eat(info, philo);
		else if (philo->status == SLEEP)
			philo_sleep(info, philo);
		else if (philo->status == THINK)
			philo_think(info, philo);
	}	
	add_full(info, philo->n_eat);
	return (0);
}
