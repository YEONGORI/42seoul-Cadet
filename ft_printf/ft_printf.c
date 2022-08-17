/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:20:51 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/31 13:55:15 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	gogogo(va_list ap, char c)
{
	int r;

	if (c == 'c')
		r = ft_print_char(va_arg(ap, int));
	else if (c == 's')
		r = ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		r = ft_print_ptr(va_arg(ap, void *));
	else if (c == 'd' || c == 'i')
		r = ft_print_dec(va_arg(ap, int));
	else if (c == 'u')
		r = ft_print_und(va_arg(ap, unsigned int));
	else if (c == 'x')
		r = ft_print_hex_low(va_arg(ap, unsigned int));
	else if (c == 'X')
		r = ft_print_hex_up(va_arg(ap, unsigned int));
	else
		r = ft_print_char(c);
	return (r);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		r;
	va_list	ap;

	i = -1;
	r = 0;
	va_start(ap, str);
	while (str[++i])
	{
		if (str[i] == '%')
			r += gogogo(ap, str[++i]); // %로 끝나는 경우도 생각해보자
		else
			r += ft_print_char(str[i]);
	}
	va_end(ap);
	return (r);
}
