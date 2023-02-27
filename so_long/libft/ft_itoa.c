/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:28:20 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/27 14:28:25 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_digit(int n)
{
	int			res;
	long long	l_n;

	res = 0;
	l_n = (long long)n;
	if (n < 0)
		l_n *= -1;
	if (n == 0)
		res = 1;
	while (l_n > 0)
	{
		res++;
		l_n /= 10;
	}
	return (res);
}

static char	*itoa_plus(int n)
{
	int		d;
	char	*res;

	d = get_digit(n);
	res = (char *) ft_calloc(d + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (d--)
	{
		res[d] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

static char	*itoa_minus(int n)
{
	int			d;
	long long	l_n;
	char		*res;

	d = get_digit(n);
	l_n = (long long)n * -1;
	res = (char *) ft_calloc(d + 2, sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '-';
	while (d > 0)
	{
		res[d--] = l_n % 10 + '0';
		l_n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	if (n >= 0)
		return (itoa_plus(n));
	else
		return (itoa_minus(n));
}
