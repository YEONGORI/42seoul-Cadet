/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:46:41 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 17:59:15 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	copy_env_value(char *s, int i)
{
	int	j;

	j = 0;
	while (g_env.env[i][j] && g_env[i][j] != '=')
	{
		s[j] = g_env.env[i][j];
		j++;
	}
	s[j] = 0;
}

void	set_env_return(char **new, char *s, int *i, int *len)
{
	int	j;
	int	is_env;

	j = 0;
	is_env = 0;
	if (s[*i] == '$')
		is_env = 1;
	if (is_env)
		i++;
	if (!s[*i])
	{
		*new = ft_strdup("$");
		return ;
	}
	if (s[*i] == '?' && s[*i - 1] == '$')
	{
		*new = ft_itoa(g_env.ret_exit);
		return ;
	}
	set_env_return_len(s, i, len);
	*new = malloc(sizeof(char) * (*len + 1));
	while (j < *len)
		(*new)[j++] = s[*i++];
	(*new)[j] = 0;
}

void	set_env_return_len(char *s, int *i, int *len)
{
	*len = 0;
	if (*i != 0)
	{
		while (s[*i] != '\0' && s[*i] != ' ' && s[*i] != '?'
			&& s[*i] != '=' && s[*i] != '/' && s[*i] != '*'
			&& s[*i] != '%' && s[*i] != '+' && s[*i] != '-'
			&& s[*i] != '@' && s[*i] != '#' && s[*i] != '$'
			&& s[*i] != '.' && s[*i] != ',' && s[*i] != ':')
		{
			*len++;
			*i++;
		}
	}
	else
	{
		while (s[*i] != '$' && s[*i] != '\0')
		{
			*len++;
			*i++;
		}
	}
	*i -= *len;
}
