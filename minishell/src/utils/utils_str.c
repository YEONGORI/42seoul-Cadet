/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:52:47 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 09:25:02 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

char	*ft_strncopy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

int	ft_strhei(char **square)
{
	int	hei;

	hei = 0;
	while (square[hei])
		hei++;
	return (hei);
}

int	ft_isnumeric(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\t'
			&& ((s[i] != '-' && s[i] != '+') && !ft_isdigit(s[i + 1])))
		{
			if (!ft_isdigit(s[i]))
				return (0);
		}
		if ((s[i] == '-' || s[i] == '+') && !s[i + 1])
			return (0);
	}
	return (1);
}
