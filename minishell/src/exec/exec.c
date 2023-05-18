/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:10:18 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 12:53:36 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_pipe(t_cmd_managed_list *list)
{
	while (list->next)
	{
		pipe(list->fd);
		list = list->next;
	}
}

void	choose_execution(t_cmd_managed_list *list)
{
	if (is_builtin_cmd(list->cmd->av[0]))
		exec_builtin(list, list->cmd->av[0]);
	else
	{
		list->cmd->av[0] = path_finder(list->cmd->av[0]);
		for (int i=0; i<ft_strhei(list->cmd->av); i++)
			printf("%s\n", list->cmd->av[i]);
		execve(list->cmd->av[0], list->cmd->av, g_env.env);
	}
	while (list->prev)
		list = list->prev;
	free_square(g_env.env);
	free_cmd_managed_list(list);
	if (g_env.cmd_not_found)
		exit(127);
	exit(0);
}

void	child_execution(t_cmd_managed_list *list)
{
	list->pid = fork();
	if (list->pid == 0)
	{
		printf("%d %d\n", list->cmd->in_desc, list->cmd->out_desc);
		if (list->next && list->cmd->out_desc == 0)
			dup2(list->fd[1], STDOUT_FILENO);
		if (list->prev && list->cmd->in_desc == 0)
			dup2(list->prev->fd[0], STDIN_FILENO);
		close_files(list);
		redirection_cmd(list);
		if (list->cmd->av[0])
			choose_execution(list);
		exit(0);
	}
	close_files(list);
}

void	execution(t_cmd_managed_list *list)
{
	int					status;
	t_cmd_managed_list	*prev;

	prev = list;
	if (single_cmd(list))
		return ;
	init_pipe(list);
	while (list)
	{
		get_path(list);
		child_execution(list);
		free_square(g_env.path);
		list = list->next;
	}
	while (prev->prev)
		prev = prev->prev;
	while (prev)
	{
		waitpid(prev->pid, &status, 0);
		g_env.ret_exit = WEXITSTATUS(status);
		prev = prev->next;
	}
}
