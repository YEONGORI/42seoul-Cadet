/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:28:21 by yeongele          #+#    #+#             */
/*   Updated: 2022/08/19 16:15:44 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ch_av(char *av)
{
	int	i;

	i = -1;
	if (!av)
		return (1);
	while (av[++i])
		if ((av[i] < '0' || av[i] > '9') && av[i] != '-')
			return (1);
	return (0);
}

int	conv_av(char *av)
{
	int	i;
	int	r;
	int	m;

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
	return (r * m);
}

int	init_stack(int ac, char *av[], twll **a)
{
	twll	*new;

	new = NULL;
	if (ac <= 1 || av == NULL || *av == NULL)
		return (1);
	for (int i = 1; i < ac; i++)
		if (ch_av(av[i]))
			return (1);
	for (int i = ac - 1; i > 0; i--)
	{
		new = ft_lstnew(conv_av(av[i]));
		if (!new)
			ft_lstclear(a);
		ft_lstadd_front(a, new);
	}
	return (0);
}
