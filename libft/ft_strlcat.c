/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:34 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 18:20:55 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;

	i = 0;
	dest_l = 0;
	src_l = 0;
	while (dest[dest_l] != 0)
		dest_l++;
	while (src[src_l] != 0)
		src_l++;
	if (dest_l >= size && size == 0)
		return (src_l + size);
	while (dest_l < size - 1 && src[i] != 0)
		dest[dest_l++] = src[i++];
	dest[dest_l] = '\0';
	return (src_l + dest_l);
}
