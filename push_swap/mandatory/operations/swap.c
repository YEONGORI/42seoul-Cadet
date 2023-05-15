/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:05:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/29 16:52:43 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack **lst)
{
	int	size;
	int	tmp;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	tmp = (*lst)-> data;
	(*lst)-> data = (*lst)-> next ->data;
	(*lst)-> next -> data = tmp;
	tmp = (*lst)-> index;
	(*lst)-> index = (*lst)-> next -> index;
	(*lst)-> next -> index = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **lst)
{
	int	size;
	int	tmp;

	size = get_size(lst);
	if (size <= 1 || lst == NULL)
		return ;
	tmp = (*lst)-> data;
	(*lst)-> data = (*lst)-> next ->data;
	(*lst)-> next -> data = tmp;
	tmp = (*lst)-> index;
	(*lst)-> index = (*lst)-> next -> index;
	(*lst)-> next -> index = tmp;
	write(1, "sb\n", 3);
}
