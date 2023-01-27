#include "../push_swap.h"

void	swap_a(s_stack **lst)
{
	int	size;
	int	tmp;
	
	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return;
	tmp = (*lst) -> data;
	(*lst) -> data = (*lst) -> next ->data;
	(*lst) -> next -> data = tmp;
	tmp = (*lst) -> index;
	(*lst) -> index = (*lst) -> next -> index;
	(*lst) -> next -> index = tmp;
	write(1, "sa\n", 4);
}

void	swap_b(s_stack **lst)
{
	int	size;
	int	tmp;
	
	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return;
	tmp = (*lst) -> data;
	(*lst) -> data = (*lst) -> next ->data;
	(*lst) -> next -> data = tmp;
	tmp = (*lst) -> index;
	(*lst) -> index = (*lst) -> next -> index;
	(*lst) -> next -> index = tmp;
	write(1, "sb\n", 4);
}