#include "../push_swap.h"

void	rotate_a(s_stack **lst) // 첫번째 원소를 가장 마지막으로
{
	s_stack	*tmp;
	s_stack *bottom;

	tmp = *lst;
	*lst = (*lst) -> next;
	bottom = get_bottom(*lst);
	tmp -> next = NULL;
	bottom -> next = tmp;
	write(1, "ra\n", 4);
}

void	rotate_b(s_stack **lst)
{
	s_stack	*tmp;
	s_stack *bottom;

	tmp = *lst;
	*lst = (*lst) -> next;
	bottom = get_bottom(*lst);
	tmp -> next = NULL;
	bottom -> next = tmp;
	write(1, "rb\n", 4);
}

void	rotate_both(s_stack **a, s_stack **b)
{
	s_stack	*tmp;
	s_stack *bottom;

	tmp = *a;
	*a = (*a) -> next;
	bottom = get_bottom(*a);
	tmp -> next = NULL;
	bottom -> next = tmp;

	tmp = *b;
	*b = (*b) -> next;
	bottom = get_bottom(*b);
	tmp -> next = NULL;
	bottom -> next = tmp;
	write(1, "rr\n", 4);
}