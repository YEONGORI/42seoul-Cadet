#include "../push_swap.h"

void	reverse_a(s_stack **lst)
{
	s_stack	*tmp;

	tmp = *lst;
	while (tmp -> next)
		tmp = tmp -> next;

	ft_lstadd_front(lst, ft_lstnew(tmp->data));
	tmp -> prev -> next = NULL;
	ft_lstdelone(tmp);
	write(1, "rra\n", 5);
}

void	reverse_b(s_stack **lst)
{
	s_stack	*tmp;

	tmp = *lst;
	while (tmp -> next)
		tmp = tmp -> next;

	ft_lstadd_front(lst, ft_lstnew(tmp->data));
	tmp -> prev -> next = NULL;
	ft_lstdelone(tmp);
	write(1, "rrb\n", 5);
}