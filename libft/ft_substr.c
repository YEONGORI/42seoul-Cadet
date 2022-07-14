/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:46:14 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/14 15:16:45 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = -1;
	if (ft_strlen(s) == 0 || start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (++i < len && s[start + i] != 0)
		ptr[i] = s[start + i];
	ptr[i] = 0;
	return (ptr);
}
