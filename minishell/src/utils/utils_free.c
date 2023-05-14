/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:37:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 21:20:07 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_square(char *square)
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

void	free_redirect_list(t_redirect_list *redirect_list)
{
	t_redirect_list	*tmp;

	while (redirect_list)
	{
		tmp = redirect_list;
		redirect_list = redirect_list->next;
		free(tmp->file);
		free(tmp);
	}
}

void	free_p_cmd_list(t_p_cmd_list *p_cmd_list)
{
	t_p_cmd_list	*tmp;

	while (p_cmd_list)
	{
		tmp = p_cmd_list;
		p_cmd_list = p_cmd_list->next;
		free_token_list(tmp->cmd->arg);
		free_redirection_list(tmp->cmd->redirection);
		free(tmp->cmd);
		free(tmp);
	}
}

void	free_p_cmd_managed_list(t_p_cmd_managed_list *p_cmd_managed_list)
{
	t_p_cmd_managed_list	*tmp;
	t_p_cmd_managed_list	*head;

	head = p_cmd_managed_list;
	while (head)
	{
		tmp = head;
		head = head->next;
		free_square(tmp->cmd->av);
		free(tmp->cmd);
		free(tmp);
	}
}