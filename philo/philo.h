/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:13:35 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/18 16:13:28 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_must_eat;
	long long		t_start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	int			status;
	int			c_eat;
	long long	t_last_eat;
	t_info		*info;
	pthread_t	thread;
}	t_philo;

/* utils.c */
int			is_digit(char **av);
int			char_to_int(const char *s);
long long	set_time(void);

/* init.c */
int			init_info(int ac, char **av, t_info *info);
int			init_philo(t_info *info, t_philo **philo);
int			init_mutex(t_info *info);

/* action */
int			start_action(t_info *info, t_philo *philo);
void		philo_print(int id, int status, t_info *info);
void		philo_wait(long long t);

#endif