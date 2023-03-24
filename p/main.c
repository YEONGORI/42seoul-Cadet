/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:16:24 by jihyukim          #+#    #+#             */
/*   Updated: 2022/09/08 15:59:13 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_info *info, t_philo **philo)
{
	int	i;

	if (info->n_philo == 1)
		pthread_detach((*philo)[0].thread);
	else
	{
		i = -1;
		while (++i < info->n_philo)
			pthread_join((*philo)[i].thread, 0);
	}
	i = -1;
	while (++i < info->n_philo)
		pthread_mutex_destroy(&(info->fork[i]));
	pthread_mutex_destroy(&(info->print));
	pthread_mutex_destroy(&(info->check_death));
	pthread_mutex_destroy(&(info->check_full));
	pthread_mutex_destroy(&(info->check_last_eat));
	free(info->fork);
	free(*philo);
}

int	set_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->n_philo)
	{
		if (pthread_mutex_init(&info->fork[i], 0) != 0)
			return (1);
	}	
	if (pthread_mutex_init(&info->print, 0) != 0)
		return (1);
	if (pthread_mutex_init(&info->check_death, 0) != 0)
		return (1);
	if (pthread_mutex_init(&info->check_full, 0) != 0)
		return (1);
	if (pthread_mutex_init(&info->check_last_eat, 0) != 0)
		return (1);
	return (0);
}

int	set_info(t_info *info, char *argv[])
{
	info->n_philo = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (info->n_philo <= 0 || info->t_die <= 0 || info->t_eat <= 0
		|| info->t_sleep <= 0)
		return (1);
	info->t_start = get_time();
	info->n_full_philo = 0;
	info->is_dead = 0;
	if (argv[5])
	{
		info->n_must_eat = ft_atoi(argv[5]);
		if (info->n_must_eat <= 0)
			return (1);
	}
	else
		info->n_must_eat = -1;
	return (0);
}

int	set_philo(t_info *info, t_philo **philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * (info->n_philo));
	if (!(*philo))
	{
		free(info->fork);
		return (1);
	}
	i = -1;
	while (++i < info->n_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].left = i;
		(*philo)[i].right = i + 1;
		if (i + 1 == info->n_philo)
			(*philo)[i].right = 0;
		(*philo)[i].t_last_eat = get_time();
		(*philo)[i].n_eat = 0;
		(*philo)[i].status = EAT;
		(*philo)[i].info = info;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (!(argc == 5 || argc == 6) || check_digit(argv))
		return (printf("wrong parameters\n"));
	if (set_info(&info, argv))
		return (printf("invalid parameters\n"));
	info.fork = malloc(sizeof(pthread_mutex_t) * info.n_philo);
	if (!info.fork)
		return (1);
	if (set_philo(&info, &philo))
		return (printf("set_philo failed\n"));
	if (set_mutex(&info))
		return (printf("set_mutex failed\n"));
	if (philo_start(&info, philo))
		return (printf("philo_start failed\n"));
	morintoring(&info, &philo);
	free_all(&info, &philo);
	return (0);
}
