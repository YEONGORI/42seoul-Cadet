/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:36:18 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 20:32:26 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		flag;
	size_t	i;
	size_t	j;

	flag = 0;
	i = -1;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[++i] != 0 && flag == 0 && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = -1;
			while (needle[++j] != 0)
				if (needle[j] != haystack[i + j])
					break ;
			if (j == ft_strlen(needle))
				flag = 1;
		}
	}
	if (flag == 0)
		return (0);
	return ((char *)haystack + i - 1);
}
