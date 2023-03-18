/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:13:24 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/18 11:33:29 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_info	info;

	if ((ac != 5 && ac != 6) || !is_digit(av))
		return (printf("ERROR: Invalid Parameters\n"));
	if (set_info(ac, av, &info))
		return (printf("ERROR: Invalid Info\n"));
}