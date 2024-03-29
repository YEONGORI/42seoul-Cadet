/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:18:01 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/09 17:38:20 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_un;
	unsigned char	*s2_un;

	i = -1;
	s1_un = (unsigned char *)s1;
	s2_un = (unsigned char *)s2;
	while (++i < n)
	{
		if (s1_un[i] != s2_un[i])
			return (s1_un[i] - s2_un[i]);
	}
	return (0);
}
