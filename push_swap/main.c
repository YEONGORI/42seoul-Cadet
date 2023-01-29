/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:04:23 by yeongele          #+#    #+#             */
/*   Updated: 2023/01/29 17:09:49 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	else
	{
		init_stack(argc, argv, &a);
		sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
