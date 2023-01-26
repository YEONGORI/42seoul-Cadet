#include "../push_swap.h"

void	rotate_a(s_stack **lst)
{
	s_stack	*tmp;

	tmp = ft_lstnew((*lst) -> data);
	ft_lstadd_back(lst, tmp);
	tmp = (*lst) -> next;
	ft_lstdelone(*lst);
	*lst = tmp;
	(*lst) -> prev = NULL;
	write(1, "ra\n", 4);
}

void	rotate_b(s_stack **lst)
{
	s_stack	*tmp;

	tmp = ft_lstnew((*lst) -> data);
	ft_lstadd_back(lst, tmp);
	tmp = (*lst) -> next;
	ft_lstdelone(*lst);
	*lst = tmp;
	(*lst) -> prev = NULL;
	write(1, "rb\n", 4);
}