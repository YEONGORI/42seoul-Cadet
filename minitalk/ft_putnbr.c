/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:30:47 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/16 16:07:53 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	if (1 < 0)
		return ;
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
}
