/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:07:23 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/29 18:08:12 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_position(t_stack **s)
{
	t_stack	*tmp;
	int		i;

	tmp = *s;
	i = 0;
	while (tmp)
	{
		tmp->cur_pos = i++;
		tmp = tmp -> next;
	}
}

int	get_lowest_index_position(t_stack **s)
{
	t_stack	*tmp;
	int		idx;
	int		pos;

	tmp = *s;
	idx = C_INT_MAX;
	get_position(s);
	pos = tmp -> cur_pos;
	while (tmp)
	{
		if (tmp -> index < idx)
		{
			idx = tmp -> index;
			pos = tmp -> cur_pos;
		}
		tmp = tmp -> next;
	}
	return (pos);
}

int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
	t_stack	*a_tmp;

	a_tmp = *a;
	while (a_tmp)
	{
		if (a_tmp -> index < target_idx && a_tmp -> index > b_idx)
		{
			target_idx = a_tmp -> index;
			target_pos = a_tmp -> cur_pos;
		}
		a_tmp = a_tmp -> next;
	}
	if (target_idx != C_INT_MAX)
		return (target_pos);
	a_tmp = *a;
	while (a_tmp)
	{
		if (a_tmp -> index < target_idx)
		{
			target_idx = a_tmp -> index;
			target_pos = a_tmp -> cur_pos;
		}
		a_tmp = a_tmp -> next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b -> index, C_INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
