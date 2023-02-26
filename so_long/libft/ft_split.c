/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:29:52 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/26 21:32:18 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_del(char c, char del)
{
	if (c == del)
		return (1);
	return (0);
}

static int	count_word(char const *s, char del)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && is_del(s[i], del))
			i++;
		if (s[i] && !is_del(s[i], del))
			cnt++;
		while (s[i] && !is_del(s[i], del))
			i++;
	}
	return (cnt);
}

static char	*ft_strcpy(char *dest, const char *src, char del)
{
	int	i;

	i = -1;
	while (src[++i] && src[i] != del)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

static int	ft__strlen(const char *s, char del)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != del)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	char	**res;

	i = -1;
	len = count_word(s, c);
	res = (char **) ft_calloc ((len + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (++i < len)
	{
		while (*s && is_del(*s, c))
			s++;
		res[i] = (char *) malloc(sizeof(char) * (ft__strlen(s, c) + 1));
		if (!res[i])
		{
			while (i >= 0)
				free(res[i--]);
			free(res);
			return (NULL);
		}
		res[i] = ft_strcpy(res[i], s, c);
		s += ft__strlen(res[i], c);
	}
	return (res);
}
