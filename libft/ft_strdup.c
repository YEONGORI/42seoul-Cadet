/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:06:11 by yeongele          #+#    #+#             */
/*   Updated: 2022/07/08 22:14:49 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *) malloc(sizeof(char) * (sizeof(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != 0)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}