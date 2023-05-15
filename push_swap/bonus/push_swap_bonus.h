/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:44 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 13:12:43 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define C_INT_MAX 2147483647
# define C_INT_MIN -2147483648

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				data;
	int				index;
	int				cur_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}	t_stack;

/* checker.c */
void	is_parameter_specified(char **av);
void	is_parameter_unique(char **av);
void	is_number(char *str, t_stack **a);
void	is_integer(long long n, t_stack **s);
int		is_sorted(t_stack **a);

/* init.c */
int		to_abs(int n);
int		get_max_index(t_stack *s);
int		get_size(t_stack **a);
void	init_stack(int ac, char **av, t_stack **a);
void	set_index(t_stack *s, int size);

/* utils.c */
int		to_int(char *av, t_stack **s);
void	free_stack(t_stack **s);
void	exit_error(t_stack **a, t_stack **b);
t_stack	*get_bottom(t_stack *s);
t_stack	*get_before_bottom(t_stack *s);

/* operations */
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	reverse_a(t_stack **lst);
void	reverse_b(t_stack **lst);
void	reverse_both(t_stack **a, t_stack **b);
void	rotate_a(t_stack **lst);
void	rotate_b(t_stack **lst);
void	rotate_both(t_stack **a, t_stack **b);
void	swap_a(t_stack **lst);
void	swap_b(t_stack **lst);
void	swap_both(t_stack **a, t_stack **b);

/* libft */
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstclear(t_stack **lst);
t_stack	*ft_lstnew(int val);
int		ft_lstsize(t_stack *lst);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* gnl */
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif