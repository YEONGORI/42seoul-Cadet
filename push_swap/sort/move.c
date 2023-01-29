/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:05:21 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/29 16:22:05 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_cost(t_stack	**a, t_stack	**b)
{
	t_stack	*b_tmp;
	int		size_a;
	int		size_b;

	b_tmp = *b;
	size_a = get_size(a);
	size_b = get_size(b);
	while (b_tmp)
	{
		b_tmp->cost_b = b_tmp->cur_pos;
		if (b_tmp->cur_pos > size_b / 2)
			b_tmp->cost_b = (size_b - b_tmp->cur_pos) * -1;
		b_tmp->cost_a = b_tmp->target_pos;
		if (b_tmp->target_pos > size_a / 2)
			b_tmp->cost_a = (size_a - b_tmp->target_pos) * -1;
		b_tmp = b_tmp->next;
	}
}

void	move_start(t_stack	**a, t_stack	**b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		rev_resolve_both(a, b, &cost_a, &cost_b);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		resolve_both(a, b, &cost_a, &cost_b);
	}
	resolve_a(a, &cost_a);
	resolve_b(b, &cost_b);
	push_a(a, b);
}

void	move_cheapest(t_stack	**a, t_stack	**b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = C_INT_MAX;
	while (tmp)
	{
		if (to_abs(tmp->cost_a) + to_abs(tmp->cost_b) < to_abs(cheapest))
		{
			cheapest = to_abs(tmp->cost_b) + to_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move_start(a, b, cost_a, cost_b);
}
