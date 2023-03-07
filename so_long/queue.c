/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:47:54 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/07 13:13:44 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	q_init(t_queue *q)
{
	q -> back = NULL;
	q -> front = NULL;
	q -> count = 0;
}

int	q_is_empty(t_queue *q)
{
	return (q -> count == 0);
}

void	q_push(t_queue *q, t_pair data, int init)
{
	t_node	*new;

	if (init)
	{
		q -> back = NULL;
		q -> front = NULL;
		q -> count = 0;
	}
	new = (t_node *) malloc(sizeof(t_node));
	new -> data = data;
	new -> next = NULL;
	if (q_is_empty(q))
		q -> front = new;
	else
		q -> back -> next = new;
	q -> back = new;
	q -> count++;
}

void	q_pop(t_queue *q)
{
	t_node	*tmp;

	if (q_is_empty(q))
		return ;
	tmp = q -> front;
	q -> front = tmp -> next;
	free(tmp);
	q -> count--;
}

int	q_clear(t_queue *q)
{
	while (!q_is_empty(q))
		q_pop(q);
	return (1);
}
