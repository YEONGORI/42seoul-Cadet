/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:47 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/18 11:41:42 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin_re(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != 0)
		str[j++] = s1[i];
	i = -1;
	while (s2[++i] != 0)
		str[j++] = s2[i];
	str[j++] = 0;
	free((void *)s1);
	return (str);
}

int	ft_strchr_re(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = (unsigned char)c;
	while (s[++i] != 0)
		if (s[i] == tmp)
			return (i);
	if (s[i] == 0 && tmp == '\0')
		return (i);
	return (-1);
}

void	ft_strlcpy(char *dest, const char *src, size_t datsize)
{
	size_t	i;

	if (datsize == 0)
		return ;
	i = -1;
	while (src[++i] != 0 && i < datsize - 1)
		dest[i] = src[i];
	dest[i] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tmp;
	void			*ptr;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	tmp = (unsigned char *)ptr;
	while (i < count * size)
		tmp[i++] = 0;
	return (ptr);
}
