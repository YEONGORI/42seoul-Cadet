/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:36:21 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 18:11:40 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env_value(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	if (s[0] == '$' && str[1] == NULL)
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
	after_dollar(char *s, int *i);
	while (s[i])
	{
		if (s[*i] == '$')
			is_env = 1;
		set_env_return(&new, s, &i, &len);
		if (is_env)
		{
			if (ft_isdigit(new[0]))
				ret = ft_strjoin(ret, new);
			if (get_env(new))
				ret = ft_strjoin(ret, get_env(new));
		}
		else
			ret = ft_strjoin(ret, new);
		free(new);
	}
	return (ret);
}

void	*set_env(t_token_list *token_list)
{
	char			*env;
	char			*before;
	t_token_list	*head;

	before = NULL;
	head = token_list;
	while (token_list)
	{
		if (ft_strchr(token_list->str, '$ ') && ft_strlen(token_list->str) > 1
			&& token_list->quotes != 1)
		{
			if (token_list->str[0] != '$ ')
				before = before_dollar(token_list->str);
			env = get_env(token_list->str, 0, 0);
			free(token_list->str);
			if (!env)
				token_list->str = ft_strdup("");
			else
				token_list->str = ft_strjoin(before, env);
			free(env);
		}
		token_list = token_list->next;
	}
	token_list = head;
}
