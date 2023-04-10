/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:53:42 by yeongele          #+#    #+#             */
/*   Updated: 2023/04/08 14:58:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	info->n_philo = char_to_int(av[1]);
	info->t_die = char_to_int(av[2]);
	info->t_eat = char_to_int(av[3]);
	info->t_sleep = char_to_int(av[4]);
	info->t_start = set_time();
	info->n_must_eat = 0;
	info->is_dead = 0;
	info->c_full = 0;
	if (ac == 6)
		info->n_must_eat = char_to_int(av[5]);
	if (info->n_philo <= 0 || info->t_die <= 0 || info->t_eat <= 0
		|| info->t_sleep <= 0 || info->n_must_eat < 0 || info->t_start < 0)
		return (1);
	return (0);
}

int	init_philo(t_info *info, t_philo **philo)
{
	int	id;

	id = -1;
	*philo = malloc(sizeof(t_philo) * (info->n_philo));
	if (!*philo)
		return (1);
	while (++id <= info->n_philo)
	{
		(*philo)[id].id = id;
		(*philo)[id].left = id;
		(*philo)[id].right = (id + 1) % info->n_philo;
		(*philo)[id].status = EAT;
		(*philo)[id].c_eat = 0;
		(*philo)[id].t_last_eat = set_time();
		(*philo)[id].info = info;
	}
	return (0);
}

int	remove_mutex(t_info *info, int n)
{
	if (n >= 3)
		pthread_mutex_destroy(&info->m_c_full);
	if (n >= 2)
		pthread_mutex_destroy(&info->m_last_eat);
	if (n >= 1)
		pthread_mutex_destroy(&info->m_dead);
	if (n >= 0)
		pthread_mutex_destroy(&info->m_print);
	return (1);
}

int	init_mutex(t_info *info)
{
	int	i;

	i = -1;
	info->fork = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!info->fork)
		return (1);
	while (++i < info->n_philo)
	{
		if (pthread_mutex_init(&info->fork[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&info->fork[i]);
			return (1);
		}
	}
	if (pthread_mutex_init(&(info->m_print), NULL))
		return (remove_mutex(info, 0));
	if (pthread_mutex_init(&(info->m_dead), NULL))
		return (remove_mutex(info, 1));
	if (pthread_mutex_init(&(info->m_last_eat), NULL))
		return (remove_mutex(info, 2));
	if (pthread_mutex_init(&(info->m_c_full), NULL))
		return (remove_mutex(info, 3));
	return (0);
}
