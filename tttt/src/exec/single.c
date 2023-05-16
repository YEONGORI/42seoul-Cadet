/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:13:07 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/15 21:33:16 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin_cmd(char	*cmd)
{
	if (!strcmp(cmd, "echo"))
		return (1);
	if (!strcmp(cmd, "cd"))
		return (1);
	if (!strcmp(cmd, "pwd"))
		return (1);
	if (!strcmp(cmd, "export"))
		return (1);
	if (!strcmp(cmd, "unset"))
		return (1);
	if (!strcmp(cmd, "env"))
		return (1);
	return (0);
}

int	redirection_cmd(t_p_cmd_managed_list *managed)
{
	if (managed->cmd->in_desc == -1 || managed->cmd->out_desc == -1)
		return (0);
	if (managed->cmd->in_desc != 0)
		dup2(managed->cmd->in_desc, STDIN_FILENO);
	if (managed->cmd->out_desc != 0)
		dup2(managed->cmd->out_desc, STDOUT_FILENO);
	return (1);
}

int	is_control_cmd(t_p_cmd_managed_list *managed)
{
	if (!is_builtin_cmd(managed->cmd->av[0]))
		return (0);
	if (!redirection_cmd(managed))
		return (0);
	return (1);
}

void	exec_builtin(t_p_cmd_managed_list *managed, char *cmd)
{
	if (!strcmp(cmd, "echo"))
		echo(managed->cmd->av);
	if (!strcmp(cmd, "cd"))
		cd(managed->cmd->av[1]);
	if (!strcmp(cmd, "pwd"))
		pwd();
	if (!strcmp(cmd, "export"))
		export(managed->cmd->av);
	if (!strcmp(cmd, "unset"))
		unset(managed->cmd->av);
	if (!strcmp(cmd, "env"))
		env();
}

int	single_cmd(t_p_cmd_managed_list *managed)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	if (managed && !managed->next)
	{
		if (is_control_cmd(managed))
		{
			exec_builtin(managed, managed->cmd->av[0]);
			dup(in, 0);
			dup(out, 1);
			close(in);
			close(out);
			return (1);
		}
	}
	close(in);
	close(out);
}
