/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:02:36 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 10:13:43 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
