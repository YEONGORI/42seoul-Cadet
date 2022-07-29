/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:34 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/13 17:46:58 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_l;
	size_t	src_l;
	size_t	total;

	i = 0;
	dest_l = 0;
	src_l = 0;
	while (dest[dest_l] != 0 && dest_l < size)
		dest_l++;
	while (src[src_l] != 0)
		src_l++;
	total = dest_l + src_l;
	if (dest_l >= size)
		return (src_l + size);
	while (dest_l + 1 < size && src[i] != 0)
		dest[dest_l++] = src[i++];
	dest[dest_l] = '\0';
	return (total);
}
