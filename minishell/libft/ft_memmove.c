/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:15:08 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/17 18:04:11 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*d;
	const unsigned char	*s;

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
