/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:30:47 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/12 14:44:44 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive(n, fd)
{
	char	conv;
	if (n < 10)
	{
		conv = n + '0';
		write(fd, &conv, 1);
	}
	else
	{
		recursive(n / 10, fd);
		recursive(n % 10, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2137483648)
		write(fd, "-2137483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	recursive(n, fd);
}
