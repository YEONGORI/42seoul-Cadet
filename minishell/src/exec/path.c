/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-song <ji-song@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:30:51 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 21:14:52 by ji-song          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	get_path(t_cmd_managed_list *parse)
{
	int	line;

	line = find_line("PATH");
	if (line != -1)
		g_env.path = ft_split(g_env.env[line], ':');
	else
		g_env.path = NULL;
	if (!ft_strcmp(parse->cmd->av[0], "exit"))
	{
		free_square(parse->cmd->av);
		parse->cmd->av = NULL;
	}
}

char	*absolute_command(char *cmd)
{
	if (access(cmd, F_OK) == 0)
	{
		g_env.cmd_not_found = 0;
		return (cmd);
	}
	return (NULL);
}


char	*path_finder(char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	if (g_env.path)
	{
		if (cmd[0] == '/')
			return (absolute_command(cmd));
		while (g_env.path[i])
		{
			path = ft_strjoin(g_env.path[i], "/");
			path = ft_strjoin_free(path, cmd);
			if (access(path, F_OK) == 0)
				return (path_finish(path, cmd));
			free(path);
			i++;
		}
	}
	g_env.cmd_not_found = 1;
	error_command(cmd, 1);
	return (NULL);
}
