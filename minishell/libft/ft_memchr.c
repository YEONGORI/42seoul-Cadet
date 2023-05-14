/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:25:56 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/10 15:59:32 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		c_un;
	const unsigned char	*s_un;

	i = -1;
	c_un = (unsigned char)c;
	s_un = (const unsigned char *)s;
	while (++i < n)
		if (s_un[i] == c_un)
			return ((unsigned char *)(s_un + i));
	return (NULL);
}
