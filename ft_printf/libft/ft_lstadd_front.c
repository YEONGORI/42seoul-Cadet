/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:42:26 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/13 21:13:39 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	else if (!lst)
		lst = &new;
	else if (!(*lst))
		*lst = new;
	else
	{
		new -> next = *lst;
		*lst = new;
	}
}
