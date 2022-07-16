/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:50:47 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/16 17:42:22 by yeongele         ###   ########.fr       */
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
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s1[++i] != 0)
		str[j++] = s1[i];
	i = -1;
	while (s2[++i] != 0)
		str[j++] = s2[i];
	str[j++] = 0;
	return (str);
}









// #include <unistd.h>
// #include <stdlib.h>

// char	*gnl(size_t a,int fd)
// {
// 	char	*t;
// 	char	c;
// 	char	k;

// 	c = 0;
// 	k = read(fd, &c, 1);
// 	if (k < 0 || (k == 0 && a == 0))
// 		return (NULL);
// 	if (k == 0 || c == '\n')
// 		t = malloc(a + 2);
// 	else
// 		t = gnl(a + 1, fd);
// 	if (t)
// 	{
// 		t[a] = c;
// 		t[a + 1] = t[a + 1] * (c != '\n');
// 	}
// 	return (t);
// }

// char	*get_next_line(int fd)
// {
// 	return (gnl(0, fd));
// }
