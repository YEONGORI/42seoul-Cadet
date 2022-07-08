/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:21:00 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 21:27:06 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t datsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	while (src[i] != 0)
		i++;
	src_len = i;
	if (datsize == 0)
		return (src_len);
	i = -1;
	while (src[++i] != 0 && i < datsize - 1)
		dest[i] = src[i];
	dest[i] = 0;
	return (src_len);
}
