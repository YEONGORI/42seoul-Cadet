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

void	reverse_both(s_stack **a, s_stack **b)
{
	s_stack	*tmp;

	tmp = *a;
	while (tmp -> next)
		tmp = tmp -> next;
	ft_lstadd_front(a, ft_lstnew(tmp->data));
	tmp -> prev -> next = NULL;
	ft_lstdelone(tmp);

	tmp = *b;
	while (tmp -> next)
		tmp = tmp -> next;
	ft_lstadd_front(b, ft_lstnew(tmp->data));
	tmp -> prev -> next = NULL;
	ft_lstdelone(tmp);
	write(1, "rrr\n", 5);
}