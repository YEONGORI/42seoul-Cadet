/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:14:27 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/03 17:23:28 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	s_init(t_stack *s)
{
	s -> top = NULL;
}

int	s_isempty(t_stack *s)
{
	return (s -> top == NULL);
}

void	s_push(t_stack *s, t_pair data)
{
	t_node	*tmp;

	tmp = (t_node *) malloc(sizeof(t_stack));
	tmp -> data = data;
	tmp -> up = s -> top;
	s -> top = tmp;
}

void	s_pop(t_stack *s)
{
	t_node	*tmp;

	if (s_isempty(s))
		return ;
	tmp = s -> top;
	s -> top = s -> top -> up;
	free(tmp);
}
