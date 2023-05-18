/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:21:44 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 09:03:56 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**create_argv(t_token_list *argu, int *ac)
{
	int				i;
	char			**av;
	t_token_list	*tmp;

	i = -1;
	*ac = 0;
	tmp = argu;
	while (tmp)
	{
		tmp = tmp->next;
		*ac += 1;
	}
	av = malloc(sizeof(char *) * (*ac + 1));
	tmp = argu;
	while (tmp)
	{
		av[++i] = ft_strdup(tmp->str);
		tmp = tmp->next;
	}
	av[i + 1] = NULL;
	return (av);
}

t_cmd_managed_list	*append_new_cmd(t_cmd_managed_list **list)
{
	t_cmd_managed_list	*new;
	t_cmd_managed_list	*temp;

	new = malloc(sizeof(t_cmd_managed_list));
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

t_cmd_managed_list	*create_cmd_managed_list(t_cmdline *cmdline)
{
	int					*fd;
	t_cmd				*cmd;
	t_cmd_managed_list	*ptr;
	t_cmd_managed_list	*prev;
	t_cmd_managed_list	*list;

	ptr = NULL;
	list = NULL;
	while (cmdline)
	{
		cmd = cmdline->cmd;
		prev = ptr;
		ptr = append_new_cmd(&list);
		ptr->prev = prev;
		ptr->cmd = malloc(sizeof(t_cmd_managed));
		fd = open_files(cmd->redirections);
		ptr->cmd->in_desc = fd[0];
		ptr->cmd->out_desc = fd[1];
		free(fd);
		ptr->cmd->av = create_argv(cmd->argu, &ptr->cmd->ac);
		ptr->cmd->is_piped = cmd->is_piped;
		cmdline = cmdline->next;
	}
	return (list);
}
