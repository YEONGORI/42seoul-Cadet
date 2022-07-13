/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:28 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/13 18:05:36 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

static int	get_len(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(s1);
	while (is_set(s1[++i], set))
		len--;
	i = ft_strlen(s1);
	while (len > 0 && is_set(s1[--i], set))
		len--;
	return (len);
}

static void	do_trim(char const *s1, char const *set, char *res)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = ft_strlen(s1);
	k = 0;
	while (is_set(s1[++i], set))
		;
	while (is_set(s1[--j], set))
		;
	while (i < j + 1)
		res[k++] = s1[i++];
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(s1))
		return (ft_strdup(s1));
	res = (char *) ft_calloc(get_len(s1, set) + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (!get_len(s1, set))
	{
		*res = 0;
		return (res);
	}
	do_trim(s1, set, res);
	return (res);
}
