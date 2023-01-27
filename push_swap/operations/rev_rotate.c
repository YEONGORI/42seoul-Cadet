#include "../push_swap.h"

void	reverse_a(s_stack **lst) // 마지막 원소를 가장 첫번째로
{
	s_stack	*tmp;
	s_stack	*bottom;
	s_stack	*before_bottom;

	bottom = get_bottom(*lst);
	before_bottom = get_before_bottom(*lst);
	tmp = *lst;
	*lst = bottom;
	(*lst) -> next = tmp;
	before_bottom -> next = NULL;
	write(1, "rra\n", 5);
}

void	reverse_b(s_stack **lst)
{
	s_stack	*tmp;
	s_stack	*bottom;
	s_stack	*before_bottom;

	bottom = get_bottom(*lst);
	before_bottom = get_before_bottom(*lst);
	tmp = *lst;
	*lst = bottom;
	(*lst) -> next = tmp;
	before_bottom -> next = NULL;
	write(1, "rrb\n", 5);
}

void	reverse_both(s_stack **a, s_stack **b)
{
	s_stack	*tmp;
	s_stack	*bottom;
	s_stack	*before_bottom;

	bottom = get_bottom(*a);
	before_bottom = get_before_bottom(*a);
	tmp = *a;
	*a = bottom;
	(*a) -> next = tmp;
	before_bottom -> next = NULL;
	bottom = get_bottom(*b);
	before_bottom = get_before_bottom(*b);
	tmp = *b;
	*b = bottom;
	(*b) -> next = tmp;
	before_bottom -> next = NULL;
	write(1, "rrr\n", 5);
}