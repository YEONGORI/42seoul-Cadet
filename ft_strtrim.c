/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:28 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/11 22:56:33 by yeongele         ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(s1))
		return (ft_strdup(s1));
	res = (char *) malloc(sizeof(char) * (get_len() + 1));
	return (NULL);
}

int	main(void)
{
	char const *s1 = "   \t\t\n  aa \t   \n ";
	char const set[3] = {'\t', ' ', '\n'};
	ft_strtrim(s1, set);
	return (0);
}
