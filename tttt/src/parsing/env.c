/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:36:21 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 22:41:16 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env_value(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	if (s[0] == '$' && s[1] == '\0')
		return ("$");
	while (g_env.env[++i])
	{
		j = 0;
		while (g_env.env[i][j] && g_env.env[i][j] != '=')
			j++;
		tmp = malloc(sizeof(char) * (j + 1));
		copy_env_value(tmp, i);
		if (!ft_strcmp(tmp, s))
		{
			free(tmp);
			return (g_env.env[i] + j + 1);
		}
		free(tmp);
	}
	return (NULL);
}

char	*get_env(char *s, int len, int is_env)
{
	int		i;
	char	*ret;
	char	*new;

	ret = NULL;
	after_dollar(s, &i);
	while (s[i])
	{
		if (s[i] == '$')
			is_env = 1;
		create_env_return(&new, s, &i, &len);
		if (is_env)
		{
			if (ft_isdigit(new[0]))
				ret = ft_strjoin_free(ret, new);
			if (get_env_value(new))
				ret = ft_strjoin_free(ret, get_env_value(new));
		}
		else
			ret = ft_strjoin_free(ret, new);
		free(new);
	}
	return (ret);
}

void	set_env(t_token_list *token)
{
	char			*env;
	char			*before;
	t_token_list	*head;

	before = NULL;
	head = token;
	while (token)
	{
		if (ft_strchr(token->str, '$')
			&& ft_strlen(token->str) > 1
			&& token->quotes != 1)
		{
			if (token->str[0] != '$')
				before = before_dollar(token->str);
			env = get_env(token->str, 0, 0);
			free(token->str);
			if (!env)
				token->str = ft_strdup("");
			else
				token->str = ft_strjoin_free(before, env);
			free(env);
		}
		token = token->next;
	}
	token = head;
}
