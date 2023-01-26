/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:44 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/26 18:00:59 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_stack
{
	struct	t_stack *next;
	struct	t_stack *prev;
	int		data;
}	s_stack;


#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include <unistd.h>

/* checker.c */
void	is_parameter_specified(char **av);
void	is_parameter_unique(char **av);
void	is_number(char *str);
void	is_integer(long long n);
int		is_sorted(s_stack **a);

/* init_stack.c */
int		get_max_data(s_stack *s);
int		get_size(s_stack **a);
int		to_int(char *av);
void	init_stack(int ac, char **av, s_stack **a);

/* sort stack.c */
void	sort_stack(s_stack **s);

/* operations */
void	push_a(s_stack **push_ll, s_stack **pop_ll);
void	push_b(s_stack **push_ll, s_stack **pop_ll);
void	reverse_a(s_stack **lst);
void	reverse_b(s_stack **lst);
void	rotate_a(s_stack **lst);
void	rotate_b(s_stack **lst);
void	swap_a(s_stack **lst);
void	swap_b(s_stack **lst);

/* sort */
void	sort_three_param(s_stack **a);

/* libft */
void	ft_lstadd_front(s_stack **lst, s_stack *new);
void	ft_lstadd_back(s_stack **lst, s_stack *new);
int		ft_lstclear(s_stack **lst);
void	ft_lstdelone(s_stack *lst);
s_stack	*ft_lstnew(int val);
int		ft_lstsize(s_stack *lst);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);

#endif