/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:13:35 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/17 13:20:26 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		n_must_eat;
	
}	t_info;

typedef struct s_philo
{
	t_info		*info;
}	t_philo;
/* utils.c */
int		is_digit(char **av);

#endif