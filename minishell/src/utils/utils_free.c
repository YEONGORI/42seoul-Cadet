/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:37:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/17 20:26:03 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_square(char **square)
{
	int	i;

	i = 0;
	if (square)
	{
		while (square[i])
			free(square[i++]);
		free(square);
	}
}

int	free_token_list(t_token_list *token_list)
{
	t_token_list	*tmp;

	while (token_list)
	{
		tmp = token_list;
		token_list = token_list->next;
		free(tmp->str);
		free(tmp);
	}
	return (1);
}

void	free_redirection_list(t_redirection_list *redirect_list)
{
	t_redirection_list	*tmp;

	while (redirect_list)
	{
		tmp = redirect_list;
		redirect_list = redirect_list->next;
		free(tmp->file);
		free(tmp);
	}
}

void	free_cmd_list(t_cmdline *cmd_list)
{
	t_cmdline	*tmp;

	while (cmd_list)
	{
		tmp = cmd_list;
		cmd_list = cmd_list->next;
		free_token_list(tmp->cmd->argu);
		free_redirection_list(tmp->cmd->redirections);
		free(tmp->cmd);
		free(tmp);
	}
}

void	free_cmd_managed_list(t_cmd_managed_list *cmd_managed_list)
{
	t_cmd_managed_list	*tmp;
	t_cmd_managed_list	*head;

	head = cmd_managed_list;
	while (head)
	{
		tmp = head;
		head = head->next;
		free_square(tmp->cmd->av);
		free(tmp->cmd);
		free(tmp);
	}
}