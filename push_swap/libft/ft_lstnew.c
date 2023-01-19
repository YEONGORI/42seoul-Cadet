/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:51:06 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/19 16:51:08 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

twll	*ft_lstnew(int val)
{
	twll	*new;

	new = malloc(sizeof(twll));
	if (!new)
		return (NULL);
	new -> data = val;
	new -> next = NULL;
	new -> prev = NULL;
	
	return (new);
}
