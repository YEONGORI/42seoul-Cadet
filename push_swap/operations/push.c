#include "../push_swap.h"

void	push_a(s_stack **push_ll, s_stack **pop_ll)
{
	s_stack	*tmp;

	tmp = (*pop_ll) -> next;
	ft_lstadd_front(push_ll, ft_lstnew((*pop_ll) -> data));
	ft_lstdelone(*pop_ll); // 여기서 모든 리스트가 지워지진 않을지 의심됨
	*pop_ll = tmp;
	(*pop_ll) -> prev = NULL;
	write(1, "pa\n", 4);
}

void	push_b(s_stack **push_ll, s_stack **pop_ll)
{
	s_stack	*tmp;

	tmp = (*pop_ll) -> next;
	ft_lstadd_front(push_ll, ft_lstnew((*pop_ll) -> data));
	ft_lstdelone(*pop_ll); // 여기서 모든 리스트가 지워지진 않을지 의심됨
	*pop_ll = tmp;
	(*pop_ll) -> prev = NULL;
	write(1, "pb\n", 4);
}