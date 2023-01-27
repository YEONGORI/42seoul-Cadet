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

void	rotate_both(s_stack **a, s_stack **b)
{
	s_stack	*tmp;

	tmp = ft_lstnew((*a) -> data);
	ft_lstadd_back(a, tmp);
	tmp = (*a) -> next;
	ft_lstdelone(*a);
	*a = tmp;
	(*a) -> prev = NULL;
	tmp = ft_lstnew((*b) -> data);
	ft_lstadd_back(b, tmp);
	tmp = (*b) -> next;
	ft_lstdelone(*b);
	*b = tmp;
	(*b) -> prev = NULL;
	write(1, "rr\n", 4);
}