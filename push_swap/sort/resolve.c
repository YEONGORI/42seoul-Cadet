#include "../push_swap.h"

void	rev_resolve_both(s_stack **a, s_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		reverse_both(a, b);
	}
}

void	resolve_both(s_stack **a, s_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_both(a, b);
	}
}

void	resolve_a(s_stack **a, int *cost_a)
{
	while (*cost_a)
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

void	resolve_b(s_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rotate_a(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			reverse_a(b);
			(*cost_b)++;
		}
	}
}