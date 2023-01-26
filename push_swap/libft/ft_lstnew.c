/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:51:06 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/26 15:06:17 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

s_stack	*ft_lstnew(int val)
{
	s_stack	*new;

	new = malloc(sizeof(s_stack));
	if (!new)
		return (NULL);
	new -> data = val;
	new -> next = NULL;
	new -> prev = NULL;
	
	return (new);
}
