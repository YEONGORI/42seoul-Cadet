/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:30:51 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/17 21:58:04 by yeongele         ###   ########.fr       */
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

char	*path_finder(char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	if (g_env.path)
	{
		while (g_env.path[i])
		{
			path = ft_strjoin(g_env.path[i], "/");
			path = ft_strjoin_free(path, cmd);
			if (access(path, F_OK) == 0)
			{
				free(cmd);
				g_env.cmd_not_found = 0;
				return (path);
			}
			free(path);
			i++;
		}
	}
	g_env.cmd_not_found = 1;
	error_command(cmd, 1);
	return (NULL);
}
