/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:19:00 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 22:49:17 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	tmp = (unsigned char)c;
	while (s[++i] != 0)
		if (s[i] == tmp)
			return ((char *)(s + i));
	if (s[i] == 0 && tmp == '\0')
		return ((char *)(s + i));
	return (0);
}
