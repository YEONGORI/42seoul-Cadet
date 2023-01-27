#include "../push_swap.h"

void	sort_three_param(s_stack **a)
{
	int	max_index;

	max_index = get_max_index(*a);
	if (max_index == (*a) -> index)
		rotate_a(a);
	else if (max_index == (*a) -> next -> index)
		reverse_a(a);
	if ((*a) -> index > (*a) -> next -> index)
		swap_a(a);
}

void	push_params_to_b(s_stack **a, s_stack **b)
{
	int	a_size;
	int push_cnt;
	int i;

	a_size = get_size(a);
	push_cnt = 0;
	i = 0;
	while (a_size >= 5 && i < a_size && push_cnt < a_size / 2)
	{
		if ((*a) -> index <= a_size / 2)
		{
			push_b(a, b);
			push_cnt++;
		}
		else
			rotate_a(a);
	}
	while (a_size - push_cnt > 3)
	{
		push_b(a, b);
		push_cnt++;
	}
	
}

void	sort_params(s_stack **a, s_stack **b)
{
	push_params_to_b(a, b);
	sort_three_param(a);
	while (*b)
	{
		get_target_position(a, b);
		get_cost(a, b);
		do_cheapest_move(a, b);
	}
	// if (!is_sorted(*a))
	// 	shift_stack(a);
}