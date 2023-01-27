#include "../push_swap.h"

void	get_position(s_stack **s)
{
	s_stack *tmp;
	int		i;

	tmp = *s;
	i = 0;
	while (tmp)
	{
		tmp->cur_pos = i++;
		tmp = tmp -> next;
	}
}

int	get_target(s_stack **a, int b_idx, int target_idx, int target_pos)
{
	s_stack *a_tmp;

	a_tmp = a;
	while (a_tmp)
	{
		if (a_tmp -> index < target_idx && a_tmp -> index > b_idx)
		{
			target_idx = a_tmp -> index;
			target_pos = a_tmp -> cur_pos;
		}
		a_tmp = a_tmp -> next;
	}
	if (target_idx != 2147483647)
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

int	get_target_position(s_stack **a, s_stack **b)
{
	s_stack *tmp_b;
	int		target_pos;

	tmp_b = *b;
	get_position(a);
	get_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(a, tmp_b -> index, 2147483647, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}