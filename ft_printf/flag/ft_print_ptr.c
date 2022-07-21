/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:42:44 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/21 21:43:28 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	p_recursive(unsigned int *ad, char *hex, int *t)
{
	if (ad / 16 == 0)
		t += write(1, hex[ad], 1);
	else
	{
		p_recursive(ad / 16, hex, t);
		p_recursive(ad % 16, hex, t);
	}
}

int	ft_print_ptr(void *addr)
{
	int				t;
	char			*hex;
	unsigned long	ad;

	t = 0;
	hex = "0123456789abcdef";
	ad = (unsigned long)addr;
	p_recursive(ad, hex, &t);
	return (t);
}

int main(void)
{
	char a = '1';
	print_address(&a);
	printf("\n");
	printf("%p", &a);
}