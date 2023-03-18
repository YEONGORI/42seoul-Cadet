/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:53:42 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/18 15:48:20 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_info(int ac, char **av, t_info *info)
{
	info->n_philo = char_to_int(av[1]);
	info->t_die = char_to_int(av[2]);
	info->t_eat = char_to_int(av[3]);
	info->t_sleep = char_to_int(av[4]);
	info->n_must_eat = 0;
	info->t_start = set_time();
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

int	init_mutex(t_info *info)
{
	int	i;

	i = -1;
	info->fork = malloc(sizeof(pthread_mutex_t) * info->n_philo);
	if (!info->fork)
		return (1);
	while (++i < info->n_philo)
		if (pthread_mutex_init(&info->fork[i], NULL))
			return (1);
	if (pthread_mutex_init(&(info->print), NULL))
		return (1);
	return (0);
}
