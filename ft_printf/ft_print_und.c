/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_und.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:35:08 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/29 16:18:05 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	u_recursive(unsigned int n, int *t)
{
	char	conv;

	if (n < 10)
	{
		conv = n + '0';
		*t += write(1, &conv, 1);
	}
	else
	{
		u_recursive(n / 10, t);
		u_recursive(n % 10, t);
	}
}

int	ft_print_und(unsigned int n)
{
	int	t;

	t = 0;
	u_recursive(n, &t);
	return (t);
}