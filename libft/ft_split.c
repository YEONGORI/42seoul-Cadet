/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:29:52 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/12 16:06:50 by yeongele         ###   ########.fr       */
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

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] && is_del(s[i], del))
			i++;
		if (s[i] && !is_del(s[i], del))
			cnt++;
		while (s[i] && !is_del(s[i], del))
			i++;
	}
	printf("cnt:  %d\n", cnt);
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
	char	**res;

	i = -1;
	res = (char **) malloc (sizeof(char *) * (cnt_str(s, c) + 1));
	if (!res)
		return (NULL);
	res[cnt_str(s, c)] = 0;
	while (*s)
	{
		while (*s && is_del(*s, c))
			s++;
		res[++i] = (char *) malloc(sizeof(char) * (ft__strlen(s, c) + 1));
		if (!res[i])
		{
			while (i > 0)
				free(res[i--]);
			return (NULL);
		}
		res[i] = ft_strcpy(res[i], s, c);
		s += ft__strlen(s, c);
	}
	return (res);
}

int	ft_count(char **str)
{
	int	i = 0;

	while (str[i] != NULL)
		i++;
	if (str[i] == NULL)
		i++;
	return (i);
}

int	main(void)
{
	char **res = ft_split("split    ||this|for|me|||||!|", '|');
	printf("len = %d\n", ft_count(res));
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < (int)strlen(res[i]); j++)
		{
			if (res[i] != NULL)
				printf("%c", res[i][j]);
		}
		printf("\n");
	}
	return (0);
}
