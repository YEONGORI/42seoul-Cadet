/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:46:14 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/09 12:56:05 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (!ptr || !s)
		return (NULL);
	while (++i < len && s[start + i] != 0)
		ptr[i] = s[start + i];
	ptr[i] = 0;
	return (ptr);
}
