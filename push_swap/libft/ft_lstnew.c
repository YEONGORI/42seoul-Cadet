/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:10:41 by yeongele          #+#    #+#             */
/*   Updated: 2022/08/19 15:54:09 by yeongele         ###   ########.fr       */
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
	
	return new;
}
