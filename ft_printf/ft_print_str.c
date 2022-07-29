/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:17:16 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/29 14:03:01 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	s;
	int	i;

	if (!str)
		str = "(null)";
	s = ft_strlen(str);
	i = (int)write(1, str, s);
	return (i);
}
