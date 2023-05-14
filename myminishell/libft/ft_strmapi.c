/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:49:14 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/13 18:49:51 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = -1;
	if (!s)
		return (NULL);
	res = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (s[++i])
		res[i] = f(i, s[i]);
	return (res);
}
