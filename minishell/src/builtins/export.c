/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:28:12 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 13:31:14 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**set_export_env(char *env_name, char *value)
{
	int		i;
	int		line;
	char	**new_env;

	i = -1;
	line = find_line(env_name);
	if (line != -1)
	{
		new_env = malloc(sizeof(char *) * (split_len(g_myenv.env) + 1));
		while (g_myenv.env[++i])
		{
			if (i == line)
				new_env[i] = ft_strjoin(join_but_no_free(env_name, "="), value);
			else
				new_env[i] = ft_strdup(g_myenv.env[i]);
		}
		new_env[i] = NULL;
		return (new_env);
	}
	new_env = malloc(sizeof(char *) * (split_len(g_myenv.env) + 2));
	while (g_myenv.env[++i])
		new_env[i] = ft_strdup(g_myenv.env[i]);
	new_env[i] = ft_strjoin(join_but_no_free(env_name, "="), value);
	new_env[i + 1] = NULL;
	return (new_env);
}

void	export_option(char **new_env, char **split, int option)
{
	char	*temp;

	if (option == 1)
	{
		new_env = set_export_env(split[0], split[1]);
		free_split(g_myenv.env);
		g_myenv.env = new_env;
	}
	if (option == 2)
	{
		temp = ft_strdup("");
		new_env = set_env(split[0], temp);
		free_split(g_myenv.env);
		g_myenv.env = new_env;
		free(temp);
	}
}

void	export(char **argu)
{
	int		i;
	char	**split;
	char	**new_env;

	i = 0;
	new_env = NULL;
	while (argu[++i] && argu[i][0])
	{
		split = ft_split(argu[i], '=');
		if (split[1])
			export_option(new_env, split, 1);
		else if (ft_strchr(arr[1], '=') && argu[1][0] != '=')
			export_option(new_env, split, 2);
		free_square(split);
	}
	if (!argu[1])
		print_export_env(g_env.env);
		g_env.ret_exit = 0;
}
