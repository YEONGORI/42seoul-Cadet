/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:09:24 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 12:20:02 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_param(t_stack **a)
{
	int	max_index;

	max_index = get_max_index(*a);
	if (max_index == (*a)->index)
		rotate_a(a);
	else if (max_index == (*a)->next->index)
		reverse_a(a);
	if ((*a)->index > (*a)->next->index)
		swap_a(a);
}

void	push_params_to_b(t_stack **a, t_stack **b)
{
	int	i;
	int	size_a;
	int	push_cnt;

	i = 0;
	size_a = get_size(a);
	push_cnt = 0;
	while (i < size_a && push_cnt < size_a / 2)
	{
		if ((*a)->index <= size_a / 2)
		{
			push_b(a, b);
			push_cnt++;
		}
		else
			rotate_a(a);
		i++;
	}
	while (size_a - push_cnt > 3)
	{
		push_b(a, b);
		push_cnt++;
	}
}

void	shift_a(t_stack **a)
{
	int	pos;
	int	size;

	pos = get_lowest_index_position(a);
	size = get_size(a);
	if (pos > size / 2)
	{
		while (pos < size)
		{
			reverse_a(a);
			pos++;
		}
	}
	else
	{
		while (pos > 0)
		{
			rotate_a(a);
			pos--;
		}
	}
}

void	sort_params(t_stack **a, t_stack **b)
{
	push_params_to_b(a, b);
	sort_three_param(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		move_cheapest(a, b);
	}
	if (!is_sorted(a))
		shift_a(a);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	len;

	len = get_size(a);
	if (len == 2)
		swap_a(a);
	else if (len == 3)
		sort_three_param(a);
	else
		sort_params(a, b);
}
