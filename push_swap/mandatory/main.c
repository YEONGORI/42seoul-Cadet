/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:23 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 13:03:43 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(t_stack *a)
{
	int		n;
	t_stack	*tmp;

	while (a->next)
	{
		n = a->data;
		tmp = a->next;
		a = a->next;
		while (a)
		{
			if (a->data == n)
				return (0);
			a = a->next;
		}
		a = tmp;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	else
	{
		init_stack(argc, argv, &a);
		sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
