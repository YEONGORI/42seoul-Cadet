/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:08:32 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/29 15:09:15 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_resolve_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		reverse_both(a, b);
	}
}

void	resolve_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_both(a, b);
	}
}

void	resolve_a(t_stack **a, int *cost_a)
{
	while (*cost_a != 0)
	{
		if (*cost_a > 0)
		{
			rotate_a(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			reverse_a(a);
			(*cost_a)++;
		}
	}
}

void	resolve_b(t_stack **b, int *cost_b)
{
	while (*cost_b != 0)
	{
		if (*cost_b > 0)
		{
			rotate_b(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			reverse_b(b);
			(*cost_b)++;
		}
	}
}
