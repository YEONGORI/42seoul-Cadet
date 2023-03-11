/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:49:21 by yeongele          #+#    #+#             */
/*   Updated: 2023/03/11 15:22:42 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	recursive(int n)
{
	char	conv;

	if (n < 10)
	{
		conv = n + '0';
		write(1, &conv, 1);
	}
	else
	{
		recursive(n / 10);
		recursive(n % 10);
	}
}

void	ft_putnbr(int n)
{
	write(1, "steps: ", 7);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	recursive(n);
	write(1, "\n", 1);
}
