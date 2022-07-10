/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:29:52 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/10 17:17:10 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_del(char c, char del)
{
	if (c == del)
		return (1);
	return (0);
}

int	cnt_str(char const *s, char del)
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
	return (cnt);
}

char	*ft_strcpy(char *dest, const char *src, char del)
{
	int	i;

	i = -1;
	while (src[++i] || src[i] != del)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		cnt;
	char	*tmp;
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
		tmp = ft_strcpy(tmp, s, c);
		res[i] = strdup(tmp);
		if (!res[i])
			return (NULL);
		s += ft_strlen(res[i]);
	}
	return (res);
}

int	main(void)
{
	char const *str = "This is me Bro ! 123 \t ";
	char **res = ft_split(str, ' ');

	for (int i = 0; i < 7; i++)
	{
		char *tmp = res[i];
		for (int j = 0; tmp[j]; j++)
			printf("%c", tmp[j]);
		printf("\n");
	}
	return (0);
}
