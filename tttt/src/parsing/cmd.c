/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:42:37 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 23:15:36 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	append_cmd_list(t_cmdline **cmd_list, t_p_cmd *cmd)
{
	t_cmdline	*tmp;
	t_cmdline	*new;

	new = (t_cmdline *)malloc(sizeof(t_cmdline));
	new->cmd = cmd;
	new->next = NULL;
	if (!*cmd_list)
		*cmd_list = new;
	else
	{
		tmp = *cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	append_token_list(t_token_list **token, char *arg)
{
	t_token_list	*tmp;
	t_token_list	*new;

	new = (t_token_list *)malloc(sizeof(t_token_list));
	new->str = ft_strdup(arg);
	new->next = NULL;
	if (!*token)
		*token = new;
	else
	{
		tmp = *token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	append_redir_list(t_redirection_list *redir, char *file, int type)
{
	t_redirection_list	*tmp;
	t_redirection_list	*new;

	new = (t_redirection_list *)malloc(sizeof(t_redirection_list));
	new->file = ft_strdup(file);
	new->direction = type;
	new->next = NULL;
	if (!*redir)
		*redir = new;
	else
	{
		tmp = *redir;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	set_cmd(t_cmd *cmd,
				t_cmdline **cmd_list,
				t_token_list *token_head,
				t_token_list *token_cur)
{
	while (token_head)
	{
		if (redirect_token_type(token_head->str, token_head) == NO_REDIR)
			append_token_list(&cmd->arg, token_head->str);
		else
		{
			append_redir_list(&cmd->redirection, token_head->next->str,
				redirect_token_type(token_head->str, token_head));
			token_head = token_head->next;
		}
		if (token_head == token_cur)
			break ;
		token_head = token_head->next;
	}
	append_cmd_list(cmd_list, cmd);
}

t_cmdline	*create_cmd_list(t_token_list *token_list)
{
	t_token_list	*token_head;
	t_cmd			*cmd;
	t_cmdline		*cmd_list;

	init_struct(&token_head, &token_list, &cmd, &cmd_list);
	while (token_list)
	{
		if (token_list->next)
		{
			if (is_pipe(token_list->next, cmd))
			{
				set_cmd(cmd, &cmd_list, token_head, token_list);
				token_list = token_list->next;
				cmd = create_cmd();
				token_head = token_list->next;
			}
		}
		else
		{
			set_cmd(cmd, &cmd_list, token_head, token_list);
			break ;
		}
		token_list = token_list->next;
	}
	return (cmd_list);
}
