/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:21:44 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 20:31:54 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_p_cmd_managed_list	*append_new_cmd(t_p_cmd_managed_list **list)
{
	t_p_cmd_managed_list	*new;
	t_p_cmd_managed_list	*temp;

	new = malloc(sizeof(t_p_cmd_managed_list));
	new->next = NULL;
	new->prev = NULL;
	new->cmd = NULL;
	if (*list == NULL)
		*list = new;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (new);
}

t_p_cmd_managed_list	*create_p_cmd_managed_list(t_p_cmd_list *cmdline)
{
	int						*fd;
	t_p_cmd					*cmd;
	t_p_cmd_managed_list	*ptr;
	t_p_cmd_managed_list	*prev;
	t_p_cmd_managed_list	*list;

	ptr = NULL;
	list = NULL;
	while (cmdline)
	{
		cmd = cmdline->cmd;
		prev = ptr;
		ptr = append_new_cmd(&list);
		ptr->prev = prev;
		ptr->cmd = malloc(sizeof(t_p_cmd_managed));
		fd = open_files(cmd->redirection);
		ptr->cmd->in_desc = fd[0];
		ptr->cmd->out_desc = fd[1];
		free(fd);
		ptr->cmd->av = create_argv(cmd->arg, &ptr->cmd->ac);
		ptr->cmd->is_pipe = cmd->is_pipe;
		cmdline = cmdline->next;
	}
	return (list);
}
