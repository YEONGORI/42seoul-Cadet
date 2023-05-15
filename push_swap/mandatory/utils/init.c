/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:28:21 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 13:12:19 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	to_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	get_max_index(t_stack *s)
{
	int	index;

	index = s->index;
	while (s)
	{
		if (s->index > index)
			index = s->index;
		s = s->next;
	}
	return (index);
}

int	get_size(t_stack **a)
{
	int		len;
	t_stack	*tmp;

	len = 1;
	tmp = *a;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	set_index(t_stack *s, int size)
{
	t_stack	*ptr;
	t_stack	*maximum;
	int		data;

	while (size-- > 0)
	{
		ptr = s;
		data = C_INT_MIN;
		maximum = NULL;
		while (ptr)
		{
			if (ptr->index == 0 && ptr->data == C_INT_MIN)
				ptr->index = 1;
			if (ptr->index == 0 && ptr->data > data)
			{
				data = ptr->data;
				maximum = ptr;
				ptr = s;
			}
			else
				ptr = ptr->next;
		}
		if (maximum != NULL)
			maximum->index = size;
	}
}

void	init_stack(int ac, char **av, t_stack **a)
{
	int		i;
	t_stack	*new;

	i = ac - 1;
	new = NULL;
	is_parameter_specified(av);
	is_parameter_unique(av);
	while (i > 0)
	{
		is_number(av[i], a);
		new = ft_lstnew(to_int(av[i], a));
		if (!new)
			ft_lstclear(a);
		ft_lstadd_front(a, new);
		i--;
	}
	if (!is_unique(*a))
		exit_error(a, NULL);
	if (is_sorted(a))
	{
		free_stack(a);
		exit(0);
	}
	set_index(*a, get_size(a) + 1);
	return ;
}
