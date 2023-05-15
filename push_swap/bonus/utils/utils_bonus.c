/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:45 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 12:37:05 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	to_int(char *av, t_stack **s)
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
	is_integer(r * m, s);
	return (r * m);
}

void	free_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s || !(*s))
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
	*s = NULL;
}

void	exit_error(t_stack **a, t_stack **b)
{
	if (a == NULL || *a != NULL)
		free_stack(a);
	if (b == NULL || *b != NULL)
		free_stack(b);
	write(2, "Error\n", 6);
	exit (1);
}

t_stack	*get_bottom(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

t_stack	*get_before_bottom(t_stack *s)
{
	while (s && s->next && s->next->next)
		s = s->next;
	return (s);
}
