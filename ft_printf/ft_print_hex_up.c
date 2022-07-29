/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:41:37 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/29 12:10:23 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_up(unsigned int n)
{
	int	i;

	i = print_ptr((long long)n, "0123456789ABCDEF", 1);
	return (i);
}