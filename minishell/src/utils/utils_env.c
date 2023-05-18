/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:46:41 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 20:41:56 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	copy_stup(int *i, int *len, char **new, char *s)
{
	int	j;

	j = 0;
	while (j < *len)
	{
		(*new)[j] = s[*i];
		j++;
		*i += 1;
	}
	(*new)[j] = 0;
}

void	copy_env_value(char *s, int i)
{
	int	j;

	j = 0;
	while (g_env.env[i][j] && g_env.env[i][j] != '=')
	{
		s[j] = g_env.env[i][j];
		j++;
	}
	s[j] = 0;
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
			*len += 1;
			*i += 1;
		}
	}
	else
	{
		while (s[*i] != '$' && s[*i] != '\0')
		{
			*len += 1;
			*i += 1;
		}
	}
	*i -= *len;
}

void	create_env_return(char **new, char *s, int *i, int *len)
{
	int	is_env;

	is_env = 0;
	if (s[*i] == '$')
		is_env = 1;
	if (is_env)
		*i += 1;
	if (!s[*i])
	{
		*new = ft_strdup("$");
		return ;
	}
	if (s[*i] == '?' && s[*i - 1] == '$')
	{
		*new = ft_itoa(g_env.ret_exit);
		*i += 1;
		return ;
	}
	set_env_return_len(s, i, len);
	*new = malloc(sizeof(char) * (*len + 1));
	copy_stup(i, len, new, s);
}
