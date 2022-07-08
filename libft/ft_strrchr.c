/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:23:49 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 18:24:21 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

size_t	ft__strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft__strlen(s) + 1;
	while (--s_len > 0)
		if (s[s_len] == c)
			return ((char *)(s + s_len));
	return (0);
}
