/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:23:13 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/24 12:03:24 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->fork[philo->left]);
	pthread_mutex_lock(&info->fork[philo->right]);
	philo_print(philo->id, philo->status, info);
	philo_print(philo->id, philo->status, info);
	philo_print(philo->id, philo->status, info);
	philo->t_last_eat = set_time();
	philo->c_eat++;
	philo_wait((long long) philo->c_eat);
	pthread_mutex_unlock(&info->fork[philo->left]);
	pthread_mutex_unlock(&info->fork[philo->right]);
	philo->status = SLEEP;
}

static void	philo_sleep(t_info *info, t_philo *philo)
{
	philo_print(philo->id, SLEEP, info);
	philo->status = THINK;
}

static void	philo_think(t_info *info, t_philo *philo)
{
	philo_print(philo->id, THINK, info);
	philo->status = EAT;
}

void	*philo_action(void	*argu)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)argu;
	info = philo->info;
	if (philo->id % 2 == 1)
		usleep(1000);
	while (1)
	{
		if ((info->n_must_eat > 0 && philo->c_eat >= info->n_must_eat)
			|| philo_check(info, philo, 0))
			break ;
		if (philo->status == EAT)
			philo_eat(info, philo);
		else if (philo->status == SLEEP)
			philo_sleep(info, philo);
		else if (philo->status == THINK)
			philo_think(info, philo);
	}
	philo_check(info, philo, 1);
	return (NULL);
}

int	start_action(t_info *info, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
	{
		philo[i].t_last_eat = set_time();
		if (pthread_create(&(philo[i].thread), NULL, philo_action, &philo[i]))
			return (1);
	}
	i = -1;
	while (1)
	{
		if (++i >= info->n_philo)
			i = 0;
		if (philo_check(info, philo, 0))
			break ;
		if (philo_check(info, philo, 1))
		{
			printf("Finished Dining.\n");
			break ;
		}
	}
	return (0);
}
