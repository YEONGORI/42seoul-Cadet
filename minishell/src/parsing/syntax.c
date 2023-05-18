/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:13:46 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/17 19:58:55 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_pipe(t_token_list *token, t_cmd *cmd)
{
	if (token->quotes != 2)
		return (0);
	if (token->str[0] == '|')
	{
		if (cmd)
			cmd->is_piped = 1;
		return (1);
	}
	return (0);
}

int	is_end_pipe(t_token_list *token)
{
	int	i;

	if (token->str[0])
	{
		i = 0;
		while (token->str[i])
			i++;
		i--;
		if (token->str[i] == '|' && token->quotes != 2)
			return (0);
		return (token->str[i] == '|');
	}
	return (0);
}

int	more_than_one_pipe(t_token_list *token_list)
{
	while (token_list)
	{
		if (token_list->next)
		{
			if (is_pipe(token_list, NULL) && is_pipe(token_list->next, NULL))
				return (1);
		}
		else if (!token_list->next && is_end_pipe(token_list))
			return (1);
		token_list = token_list->next;
	}
	return (0);
}

int	redirection_control(t_token_list *tokens)
{
	if (!tokens->next)
		return (0);
	if (redirection_token_type(tokens->next->str, tokens->next) != NO_REDIR)
		return (0);
	return (1);
}

int	check_syntax(t_token_list *token)
{
	if (is_pipe(token, NULL) || more_than_one_pipe(token))
	{
		ft_putstr_fd("$: syntax error near unexpected token '|'\n", 2);
		g_env.ret_exit = 258;
		return (0);
	}
	while (token)
	{
		if (redirection_token_type(token->str, token) != NO_REDIR)
		{
			if (!redirection_control(token))
			{
				ft_putstr_fd("$: syntax error near unexpected token 'newline'\n",
					2);
				g_env.ret_exit = 258;
				return (0);
			}
		}
		token = token->next;
	}
	return (1);
}
