/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:20:31 by jihyukim          #+#    #+#             */
/*   Updated: 2023/03/17 13:19:50 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILO_H
# define PHILO_H

# include <stdio.h>		/* printf()				*/
# include <stdlib.h>	/* malloc(), free()		*/
# include <unistd.h>	/* usleep()				*/
# include <pthread.h>	/* pthread_create()...	*/
# include <sys/time.h>	/* gettimeofday()		*/

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_info
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_must_eat;
	int				n_full_philo;
	long long		t_start;
	int				is_dead;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	check_death;
	pthread_mutex_t	check_full;
	pthread_mutex_t	check_last_eat;
}				t_info;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	long long	t_last_eat;
	int			n_eat;
	int			status;
	t_info		*info;
	pthread_t	thread;
}				t_philo;

/* utils.c */
void		prints(t_info *info, int id, int status);
void		psleep(long long t_sleep);
long long	get_time(void);
int			check_digit(char *argv[]);
int			ft_atoi(const char *str);

/* philo.c */
void		morintoring(t_info *info, t_philo **philo);
int			is_dead(t_info *info, t_philo *philo);
int			is_full(t_info *info);
int			philo_start(t_info *info, t_philo *philo);

/* act.c */
void		philo_eat(t_info *info, t_philo *philo);
void		philo_sleep(t_info *info, t_philo *philo);
void		add_full(t_info *info, int n_eat);
void		*philo_act(void *philo);

/* main.c */
void		free_all(t_info *info, t_philo **philo);
int			set_mutex(t_info *info);
int			set_info(t_info *info, char *argv[]);
int			set_philo(t_info *info, t_philo **philo);

#endif