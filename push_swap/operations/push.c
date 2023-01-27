#include "../push_swap.h"

void	push_b(s_stack **a, s_stack **b)
{
	s_stack	*tmp;

	if (*a == NULL)
		return ;
	tmp = (*a) -> next;
	(*a) -> next = *b;
	*b = *a;
	*a = tmp;
	write(1, "pa\n", 4);
}

void	push_a(s_stack **a, s_stack **b)
{
	s_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = (*b) -> next;
	(*b) -> next = *a;
	*a = *b;
	*b = tmp;
	write(1, "pb\n", 4);
}