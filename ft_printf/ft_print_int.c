/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:02:33 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/21 21:19:18 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	i_recursive(int n, int *t)
{
	char	conv;

	if (n < 10)
	{
		conv = n + '0';
		*t += write(1, &conv, 1);
	}
	else
	{
		i_recursive(n / 10, t);
		i_recursive(n % 10, t);
	}
}

int	ft_print_int(int n)
{
	int	t;

	t = 0;
	if (n == -2147483648)
	{
		t += (int)write(1, "-2147483648", 11);
		return (t);
	}
	else if (n < 0)
	{
		t += write(1, "-", 1);
		n *= -1;
	}
	i_recursive(n, &t);
	return (t);
}