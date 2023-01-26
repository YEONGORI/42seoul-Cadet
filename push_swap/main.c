/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:23 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/26 15:05:42 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	s_stack	*a;

	a = NULL;
	if (argc < 2)
		exit(1);
	else
	{
		init_stack(argc, argv, &a);
		sort_stack(&a);
	}
	return (0);
}