/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:13:24 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/24 12:50:37 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	if ((ac != 5 && ac != 6) || !is_digit(av))
		return (printf("ERROR: Invalid Parameters\n"));
	if (init_info(ac, av, &info))
		return (printf("ERROR: Invalid Info\n"));
	if (init_philo(&info, &philo))
		return (printf("ERROR: Malloc Failed\n"));
	if (init_mutex(&info))
		return (printf("ERROR: Mutex Not Created\n"));
	if (start_action(&info, philo))
		return (printf("ERROR: Dining Failed\n"));
	free_all(&info, &philo);
	return (0);
}
