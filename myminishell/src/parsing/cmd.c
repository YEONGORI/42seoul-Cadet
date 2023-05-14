/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:42:37 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 20:30:12 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	append_p_cmd_list(t_p_cmd_list **p_cmd_list, t_p_cmd *p_cmd)
{
	t_p_cmd_list	*tmp;
	t_p_cmd_list	*new;

	new = (t_p_cmd_list *)malloc(sizeof(t_p_cmd_list));
	new->cmd = p_cmd;
	new->next = NULL;
	if (!*p_cmd_list)
		*p_cmd_list = new;
	else
	{
		tmp = *p_cmd;
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

void	append_redirect_list(t_redirect_list *redirect, char *file, int type)
{
	t_redirect_list	*tmp;
	t_redirect_list	*new;

	new = (t_redirect_list *)malloc(sizeof(t_redirect_list));
	new->file = ft_strdup(file);
	new->direction = type;
	new->next = NULL;
	if (!*redirect)
		*redirect = new;
	else
	{
		tmp = *redirect;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	set_cmd(t_p_cmd *p_cmd,
				t_p_cmd_list **p_cmd_list,
				t_token_list *token_head,
				t_token_list *token_cur)
{
	while (token_head)
	{
		if (redirect_token_type(token_head->str, token_head) == NO_REDIR)
			append_token_list(&p_cmd->arg, token_head->str);
		else
		{
			append_redirect_list(&p_cmd->redirection, token_head->next->str,
				redirect_token_type(token_head->str, token_head));
			token_head = token_head->next;
		}
		if (token_head == token_cur)
			break ;
		token_head = token_head->next;
	}
	append_p_cmd_list(p_cmd_list, p_cmd);
}

t_p_cmd_list	*create_p_cmd_list(t_token_list *token_list)
{
	t_token_list	*token_head;
	t_p_cmd			*p_cmd;
	t_p_cmd_list	*p_cmd_list;

	init_struct(&token_head, &token_list, &p_cmd, &p_cmd_list);
	while (token_list)
	{
		if (token_list->next)
		{
			if (is_pipe(token_list->next, p_cmd))
			{
				set_cmd(p_cmd, &p_cmd_list, token_head, token_list);
				token_list = token_list->next;
				p_cmd = create_p_cmd_list();
				token_head = token_list->next;
			}
		}
		else
		{
			set_cmd(p_cmd, &p_cmd_list, token_head, token_list);
			break ;
		}
		token_list = token_list->next;
	}
	return (p_cmd_list);
}
