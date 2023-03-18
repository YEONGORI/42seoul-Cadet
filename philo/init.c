/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:53:42 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/18 11:58:06 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_info(int ac, char **av, t_info *info)
{
	info->n_philo = ft_atoi(av[1]);
	info->t_die = ft_atoi(av[2]);
	info->t_eat = ft_atoi(av[3]);
	info->t_sleep = ft_atoi(av[4]);
	info->n_must_eat = 0;
	info->t_start = set_time();
	if (ac == 6)
		info->n_must_eat = ft_atoi(av[5]);
	if (info->n_philo <= 0 || info->t_die <= 0 || info->t_eat <= 0
		|| info->t_sleep <= 0 || info->n_must_eat < 0 || info->t_start < 0)
		return (1);
	return (0);
}

int	set_philo(t_info *info, t_philo **philo)
{
	
}
