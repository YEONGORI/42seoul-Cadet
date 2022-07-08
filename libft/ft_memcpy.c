/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:17:19 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 18:18:05 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = -1;
	d = dest;
	s = src;
	if (num == 0 || dest == src)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	while (++i < num)
		d[i] = s[i];
	return (dest);
}
