/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:45:56 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 10:13:38 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_lstsize(t_stack *lst)
{
	int		i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
