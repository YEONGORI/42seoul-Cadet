/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:45:59 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 17:47:34 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*before_dollar(char *s)
{
	int		i;
	char	*before;

	i = -1;
	while (before[++i] != '$')
		;
	before = malloc(sizeof(char) * (i + 1));
	i = -1;
	while (s[++i] != '$')
		before[i] = s[i];
	before[i] = 0;
	return (before);
}

void	after_dollar(char *s, int *i)
{
	*i = 0;
	while (str[*i] !+ '$')
		(*i)++;
}
