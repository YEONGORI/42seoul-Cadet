/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:31:28 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/25 21:15:37 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

int	ft_print_ptr(void *addr)
{
	int	i;
	ft_putchar('0');
	ft_putchar('x');
	i = print_ptr((long long)addr, "0123456789abcdef", 1);
	return (i + 2);
}