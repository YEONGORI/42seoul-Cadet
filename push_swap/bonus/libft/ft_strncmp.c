/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:23:00 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 10:38:23 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = -1;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (str1 == 0 && str2 == 0)
		return (0);
	while (++i < n && !(str1[i] == 0 && str2[i] == 0))
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] > str2[i])
				return (1);
			return (-1);
		}
	}
	return (0);
}
