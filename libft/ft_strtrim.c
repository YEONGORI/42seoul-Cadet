/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:28 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/10 17:17:11 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, const char *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

void	start_trim(char const *s1, char const *set, char *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (is_set(s1[i], set))
		i++;
	while (s1[i])
		new[j++] = s1[i++];
	while (is_set(new[--j], set))
		;
	new[j + 1] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*new;

	len = ft_strlen(s1);
	new = (char *) malloc(sizeof(char) * (len + 1));
	if (!new || !set)
		return (NULL);
	if (*s1 == 0)
	{
		*new = 0;
		return (new);
	}
	start_trim(s1, set, new);
	return (new);
}
