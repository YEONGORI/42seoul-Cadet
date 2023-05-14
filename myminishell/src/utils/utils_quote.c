/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:36:20 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 16:27:25 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_quote(char *s, int len)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != ' ' && (len > i))
		if (s[i] == '\'' || s[i] == '\"')
			return (1);
	return (0);
}

char	*remove_quote(char *input, char *dest, int flag)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (input[++i])
	{
		if (input[i] != '\'' && input[i] != '\"')
			dest[j++] = input[i++];
		else
		{
			if (flag == 0)
				flag = 1;
			else if (input[(i++) + 1] != ' ')
				if (help_quote2(input, dest, &i, &j))
					break ;
			else
				break ;
		}
		if (input[i] == NULL)
			break ;
	}
	dest[j] = 0;
	return (dest);
}

int	help_quote1(char *input, int *i, int *len)
{
	if ((input[*i] == '\'' || input[*i] == '\"') && input[*i + 1] == '|')
		return (1);
	if (input[*i] == '\'' || input[*i] == '\"')
		(*i)++;
	while (input[*i] && input[*i] != '\''
		&& input[*i] != '\"' && input[*i] != ' ')
	{
		(*i)++;
		(*len)++;
	}
	if (input[*i] == ' ')
		return (1);
	return (0);
}

int	help_quote2(char *input, char *dest, int *i, int *len)
{
	if ((input[*i - 1] == '\"' || input[*i - 1] == '\'') && input[*i] == '|')
		return (1);
	while (input[*i] && input[*i] != '\''
		&& input[*i] != '\"' && input[*i] != ' ')
		dest[(*j)++] = input[(*i)++];
	if (input[*i] == ' ')
		return (1);
	return (0);
}
