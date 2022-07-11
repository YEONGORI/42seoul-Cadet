/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:29:52 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/11 20:28:26 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_del(char c, char del)
{
	if (c == del)
		return (1);
	return (0);
}

static int	cnt_str(char const *s, char del)
{
	int		i;
	int		cnt;

	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (i != 0 && is_del(s[i], del) && s[i + 1])
		{
			while (s[i] && is_del(s[i], del))
				i++;
			cnt++;
		}
	}
	return (cnt + 1);
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
	int		cnt;
	char	**res;

	i = -1;
	cnt = cnt_str(s, c);
	res = (char **) malloc (sizeof(char *) * (cnt + 1));
	if (!res)
		return (NULL);
	res[cnt] = NULL;
	while (++i < cnt)
	{
		while (is_del(*s, c))
			s++;
		len = ft__strlen(s, c);
		res[i] = (char *) malloc(sizeof(char) * (len + 1));
		if (!res[i])
			return (NULL);
		res[i] = ft_strcpy(res[i], s, c);
		s += len;
	}
	return (res);
}
/*
int	main(void)
{
	char const *str = "";
	char **res = ft_split(str, ' ');

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < (int)strlen(res[i]); j++)
			printf("%c ", res[i][j]);
		printf("\n");
	}
	return (0);
}
*/