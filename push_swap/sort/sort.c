#include "../push_swap.h"

void	sort_three_param(s_stack **a)
{
	int	max_data;

	max_data = get_max_data(*a);
	if (max_data == (*a) -> data)
		rotate_a(a);
	else if (max_data == (*a) -> next -> data)
		reverse_a(a);
	if ((*a) -> data > (*a) -> next -> data)
		swap_a(a);
}

void	push_params_to_b(s_stack **a, s_stack **b)
{
	int	len;
	int i;

	len = get_size(a);
}

void	sort_params(s_stack **a, s_stack **b)
{
	
}