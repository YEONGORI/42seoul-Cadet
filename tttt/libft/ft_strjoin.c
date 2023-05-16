/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 12:56:43 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 22:35:41 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(const char *s1, const char *s2)
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
	str[j] = 0;
	return (str);
}

char	*ft_strjoin_free(const char *s1, const char *s2)
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
	str[j] = 0;
	if (s1)
		free((void *)s1);
	return (str);
}
