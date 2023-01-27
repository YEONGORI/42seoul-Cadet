/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:28:21 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/27 14:22:15 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_max_index(s_stack *s)
{
	int index;

	index = s->index;
	while (s)
	{
		if (s->index > index)
			index = s->index;
		s = s->next;
	}
	return (index);
}

int	get_size(s_stack **a)
{
	int		len;
	s_stack	*tmp;

	len = 1;
	tmp = *a;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	to_int(char *av)
{
	long long	i;
	long long	r;
	long long	m;

	i = -1;
	r = 0;
	m = 1;
	if (av[0] == '-')
	{
		m = -1;
		i++;
	}
	while (av[++i])
	{
		r *= 10;
		r += (av[i] - '0');
	}
	is_integer(r * m);
	return (r * m);
}

void	set_index(s_stack *s)
{
	s_stack *ptr;
	s_stack *maximum;
	int		data;
	int		size;

	size = (get_size(&s) + 1);
	while (size-- > 0)
	{
		ptr = s;
		data = -2147483648;
		maximum = NULL;
		while (ptr)
		{
			if (ptr -> index == 0 && ptr -> data == -2147483648)
				ptr -> index = 1;
			if (ptr -> index == 0 && ptr -> data > data)
			{
				data = ptr -> data;
				maximum = ptr;
				ptr = s;
			}
			else
				ptr = ptr -> next;
		}
		if (maximum != NULL)
			maximum -> index = size;
	}
}


void	init_stack(int ac, char **av, s_stack **a)
{
	s_stack	*new;

	new = NULL;
	is_parameter_specified(av);
	is_parameter_unique(av);
	for (int i = ac - 1; i > 0; i--)
	{
		is_number(av[i]);
		new = ft_lstnew(to_int(av[i]));
		if (!new)
			ft_lstclear(a);
		ft_lstadd_front(a, new);
	}
	if (is_sorted(a))
		exit(0);
	set_index(*a);
	return;
}