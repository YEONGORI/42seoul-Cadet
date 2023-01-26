/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:49:59 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/26 18:01:11 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(s_stack **a)
{
	int		len;
	s_stack	**b;

	len = get_size(a);
	b = NULL;
	if (len == 2)
		swap_a(a);
	else if (len == 3)
		sort_three_param(a);
	else
		sort_params(a, b);
}