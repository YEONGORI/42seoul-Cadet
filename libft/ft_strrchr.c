/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:23:49 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/14 16:16:28 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			s_len;
	unsigned char	tmp;

	s_len = ft_strlen(s) + 1;
	tmp = (unsigned char)c;
	while (s_len--)
		if (s[s_len] == tmp)
			return ((char *)(s + s_len));
	return (0);
}
