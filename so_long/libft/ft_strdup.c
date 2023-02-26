/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:03:32 by yeongele          #+#    #+#             */
/*   Updated: 2023/02/26 21:25:05 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i] != 0)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}