/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:28:46 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/12 15:27:56 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(int n)
{
	int	res;

	res = 0;
	while (n > 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		m;

	m = 0;
	len = get_digit(n);
	if (n < 0)
		m = 1;
	res = (char *) malloc(sizeof(char) * (len + 1 + m));
	ft_bzero(res, ft_strlen(res));
	printf("len %d\n", len);
	// res[len + m] = 0;
	while (n > 0)
	{
		res[len-- + m] = n % 10;
		n /= 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

int main(void)
{
	printf("%s\n", ft_itoa(2137483647));
	return (0);
}