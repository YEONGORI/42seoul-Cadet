/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:51:06 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/27 20:28:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

s_stack	*ft_lstnew(int data)
{
	s_stack	*new;

	new = malloc(sizeof(s_stack));
	if (!new)
		return (NULL);
	new -> data = data;
	new -> index = 0;
	new -> next = NULL;
	new -> prev = NULL;
	new -> cur_pos = -1;
	new -> target_pos = -1;
	new -> cost_a = -1;
	new -> cost_b = -1;
	return (new);
}
