/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:13:35 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/18 11:54:27 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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
	long long	t_start;

}	t_info;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	
	t_info		*info;
}	t_philo;

/* utils.c */
int			is_digit(char **av);
int			ft_atoi(const char *s);
long long	set_time(void);

/* init.c */
int			set_info(int ac, char **av, t_info *info);

#endif