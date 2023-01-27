/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:44 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/27 23:32:54 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_stack
{
	struct	t_stack *next;
	struct	t_stack *prev;
	int		data;
	int		index; // 인덱스(스택 원소들 간의 크기 순위를 나타낸 것)를 사용해 비교를 진행한다.
	int		cur_pos; // 
	int		target_pos;
	int		cost_a;
	int		cost_b;
}	s_stack;


#include <stdio.h> // 이거 지워야함
#include <string.h> // 이거 지워야함

#include <stdlib.h> // malloc, free 주석 제거
#include <unistd.h> // read, write 주석 제거

/* checker.c */
void	is_parameter_specified(char **av);
void	is_parameter_unique(char **av);
void	is_number(char *str);
void	is_integer(long long n);
int		is_sorted(s_stack **a);

/* init.c */
int		get_max_index(s_stack *s);
int		get_size(s_stack **a);
void	init_stack(int ac, char **av, s_stack **a);
void	set_index(s_stack *s, int size);

/* utils */
int		to_int(char *av);
int		to_abs(int n);
s_stack	*get_bottom(s_stack *s);
s_stack *get_before_bottom(s_stack *s);

/* operations */
void	push_a(s_stack **a, s_stack **b);
void	push_b(s_stack **a, s_stack **b);
void	reverse_a(s_stack **lst);
void	reverse_b(s_stack **lst);
void	reverse_both(s_stack **a, s_stack **b);
void	rotate_a(s_stack **lst);
void	rotate_b(s_stack **lst);
void	rotate_both(s_stack **a, s_stack **b);
void	swap_a(s_stack **lst);
void	swap_b(s_stack **lst);

/* move.c */
void	get_cost(s_stack **a, s_stack **b);
void	move_start(s_stack **a, s_stack **b, int cost_a, int cost_b);
void	move_cheapest(s_stack **a, s_stack **b);

/* position.c */
void	get_target_position(s_stack **a, s_stack **b);
int		get_target(s_stack **a, int b_idx, int target_idx, int target_pos);
void	get_position(s_stack **s);
int		get_lowest_index_position(s_stack **s);

/* resolve.c */
void	rev_resolve_both(s_stack **a, s_stack **b, int *cost_a, int *cost_b);
void	resolve_both(s_stack **a, s_stack **b, int *cost_a, int *cost_b);
void	resolve_a(s_stack **a, int *cost_a);
void	resolve_b(s_stack **b, int *cost_b);

/* sort.c */
void	sort_three_param(s_stack **a);
void	sort_params(s_stack **a, s_stack **b);
void	sort_stack(s_stack **a, s_stack **b);
void	push_params_to_b(s_stack **a, s_stack **b);

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