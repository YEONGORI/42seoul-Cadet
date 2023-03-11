/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:47 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/26 21:30:27 by yeongele         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i] != 0)
		str[++j] = s1[i];
	i = -1;
	while (s2[++i] != 0)
		str[++j] = s2[i];
	free((void *)s1);
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = (unsigned char)c;
	while (s[++i] != 0)
		if (s[i] == tmp)
			return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	i = -1;
	if (ft_strlen(s) == 0 || start >= ft_strlen(s))
		len = 0;
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	ptr = (char *) ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (++i < len && s[start + i] != 0)
		ptr[i] = s[start + i];
	return (ptr);
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
