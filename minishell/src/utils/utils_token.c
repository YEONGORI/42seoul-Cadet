/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:58:29 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 22:59:52 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	token_len(int flag, t_redirection type)
{
	int	token;
	int	redir_len;

	redir_len = 1;
	if (type == INPUT_NEXT_LINE || type == OUTPUT_FILE_APPEND)
		redir_len = 2;
	if (flag == 0)
		token = redir_len;
	else
		token = flag;
	return (token);
}

int	get_redirection_token_type(char *s)
{
	if (*s)
	{
		if (*s == '<' && *(s + 1) != '<')
			return (INPUT_FILE);
		if (*s == '>' && *(s + 1) != '>')
			return (OUTPUT_FILE_CREATE);
	}
	if (*s && *(s + 1))
	{
		if (*s == '<' && *(s + 1) == '<')
			return (INPUT_NEXT_LINE);
		if (*s == '>' && *(s + 1) == '>')
			return (OUTPUT_FILE_APPEND);
	}
	return (NO_REDIR);
}

int	redirection_token_type(char *s, t_token_list *token)
{
	if (*s && !*(s + 1))
	{
		if (*s == '<' && token->quotes == 2)
			return (INPUT_FILE);
		if (*s == '>' && token->quotes == 2)
			return (OUTPUT_FILE_CREATE);
	}
	if (*s && *(s + 1))
	{
		if (*s == '<' && *(s + 1) == '<' && token->quotes == 2)
			return (INPUT_NEXT_LINE);
		if (*s == '>' && *(s + 1) == '>' && token->quotes == 2)
			return (OUTPUT_FILE_APPEND);
	}
	return (NO_REDIR);
}
