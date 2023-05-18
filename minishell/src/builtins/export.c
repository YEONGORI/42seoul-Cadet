/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:28:12 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/17 22:15:13 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	print_export_env(char **env)
{
	int		i;
	char	**split;

	i = -1;
	while (env[++i])
	{
		ft_putstr_fd("declare -x  ", 1);
		split = ft_split(env[i], '=');
		ft_putstr_fd(split[0], 1);
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(split[1], 1);
		ft_putstr_fd("\"\n", 1);
		free_square(split);
	}
}

char	**set_export_env(char *env_name, char *value)
{
	int		i;
	int		line;
	char	**env;

	i = -1;
	line = find_line(env_name);
	if (line != -1)
	{
		env = malloc(sizeof(char *) * (ft_strhei(g_env.env) + 1));
		while (g_env.env[++i])
		{
			if (i == line)
				env[i] = ft_strjoin_free(ft_strjoin(env_name, "="), value);
			else
				env[i] = ft_strdup(g_env.env[i]);
		}
		env[i] = NULL;
		return (env);
	}
	env = malloc(sizeof(char *) * (ft_strhei(g_env.env) + 2));
	while (g_env.env[++i])
		env[i] = ft_strdup(g_env.env[i]);
	env[i] = ft_strjoin_free(ft_strjoin(env_name, "="), value);
	env[i + 1] = NULL;
	return (env);
}

void	export_option(char **new_env, char **split, int option)
{
	char	*tmp;

	if (option == 1)
	{
		new_env = set_export_env(split[0], split[1]);
		free_square(g_env.env);
		g_env.env = new_env;
	}
	if (option == 2)
	{
		tmp = ft_strdup("");
		new_env = set_export_env(split[0], tmp);
		free_square(g_env.env);
		g_env.env = new_env;
		free(tmp);
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
		else if (ft_strchr(argu[1], '=') && argu[1][0] != '=')
			export_option(new_env, split, 2);
		free_square(split);
	}
	if (!argu[1])
		print_export_env(g_env.env);
	g_env.ret_exit = 0;
}
