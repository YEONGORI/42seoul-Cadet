/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:30:49 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/29 12:16:32 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	print_ptr(unsigned long long ptr, char *hex, int cnt)
{
	if (ptr >= 16)
	{
		cnt = print_ptr(ptr / 16, hex, cnt + 1);
		ptr %= 16;
	}
	ft_putchar(hex[ptr]);
	return (cnt);
}
