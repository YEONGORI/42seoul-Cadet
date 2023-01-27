#include "../push_swap.h"

void	push_a(s_stack **a, s_stack **b)
{
	s_stack	*tmp;

	tmp = (*b) -> next;
	ft_lstadd_front(a, ft_lstnew((*b) -> data));
	ft_lstdelone(*b); // 여기서 모든 리스트가 지워지진 않을지 의심됨
	*b = tmp;
	(*b) -> prev = NULL;
	write(1, "pa\n", 4);
}

void	push_b(s_stack **b, s_stack **a)
{
	s_stack	*tmp;

	tmp = (*a) -> next;
	ft_lstadd_front(b, ft_lstnew((*a) -> data));
	ft_lstdelone(*a); // 여기서 모든 리스트가 지워지진 않을지 의심됨
	*a = tmp;
	(*a) -> prev = NULL;
	write(1, "pb\n", 4);
}