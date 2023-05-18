/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:52 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 09:25:39 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token_list	*create_token(char *input, int len)
{
	char			*dest;
	t_token_list	*token;

	token = (t_token_list *)malloc(sizeof(t_token_list));
	if (find_quote(input, len))
	{
		dest = malloc(get_only_quotation_len(input, 0) + 1);
		if (dest == NULL)
			return (NULL);
		token->quotes = 0;
		if (input[0] == '\'')
			token->quotes = 1;
		token->str = ft_strdup(copy_only_quotation(input, dest, 0));
	}
	else
	{
		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		token->quotes = 2;
		token->str = ft_strdup(ft_strncopy(dest, input, len));
	}
	free(dest);
	return (token);
}

int	get_token_len(char *s, int len, int flag)
{
	t_redirection	type;

	while (s[++len] && s[len] != ' ' && flag == -1)
	{
		type = get_redirection_token_type(&s[len]);
		if (type != NO_REDIR)
			flag = len;
		if (s[len] == '|' || s[len + 1] == '|')
		{
			if (s[len] == '|')
				return (len + 1);
			if (s[++len] == '|' && s[len + 1] != '\'' && s[len + 1] != '\"')
				break ;
		}
		else if (s[len] == '\'' || s[len] == '\"')
		{
			len += get_quotation_len(&s[len + 1], s[len]) + 1;
			if (s[len + 1] == '|')
				return (len + 1);
		}
	}
	if (flag != -1)
		len = token_len(flag, type);
	return (len);
}

t_token_list	*create_token_list(char *input)
{
	int				len;
	t_token_list	*token;

	input += jump_space(input);
	if (!*input)
		return (NULL);
	len = get_token_len(input, -1, -1);
	token = create_token(input, len);
	token->next = create_token_list(input + len);
	return (token);
}
