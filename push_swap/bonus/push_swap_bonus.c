/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:02:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 20:06:59 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	err(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	exit(1);
}

void	operator(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "rra", 3))
		reverse_a(a);
	else if (!ft_strncmp(op, "rrb", 3))
		reverse_b(b);
	else if (!ft_strncmp(op, "rrr", 3))
		reverse_both(a, b);
	else if (!ft_strncmp(op, "ra", 2))
		rotate_a(a);
	else if (!ft_strncmp(op, "rb", 2))
		rotate_b(b);
	else if (!ft_strncmp(op, "rr", 2))
		rotate_both(a, b);
	else if (!ft_strncmp(op, "pa", 2))
		push_a(a, b);
	else if (!ft_strncmp(op, "pb", 2))
		push_b(a, b);
	else if (!ft_strncmp(op, "sa", 2))
		swap_a(a);
	else if (!ft_strncmp(op, "sb", 2))
		swap_b(b);
	else if (!ft_strncmp(op, "ss", 2))
		swap_both(a, b);
	else
		err(a, b);
}

void	bonus_routine(t_stack **a, t_stack **b, int ac)
{
	char	*line;

	line = get_next_line(0);
	free(line);
	while (line)
	{
		operator(a, b, line);
		line = get_next_line(0);
		free(line);
	}
	if (is_sorted(a) && get_size(a) == ac - 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		exit(1);
	else
	{
		init_stack(ac, av, &a);
		bonus_routine(&a, &b, ac);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
