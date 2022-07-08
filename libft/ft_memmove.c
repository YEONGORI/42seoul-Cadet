/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:15:08 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 18:18:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;

	if (s < d)
		while (num-- > 0)
			*(d + num) = *(s + num);
	else if (s != d)
		while (num-- > 0)
			*d++ = *s++;
	return (dest);
}