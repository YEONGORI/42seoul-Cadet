/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:52 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 16:34:40 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token_list	*get_token(char *input, int len)
{
	char			*dest;
	t_token_list	*token;

	token = (t_token_list *)malloc(sizeof(t_token_list));
	if (token == NULL)
		return (NULL);
	if (find_quote(input, len))
	{
		dest = malloc(get_quote_len(input, 0) + 1);
		if (dest == NULL)
			return (NULL);
		token->quotes = 0;
		if (input[0] == '\'')
			token->quotes = 1;
		token->str = ft_strdup(remove_quote(input, dest, 0));
	}
	else
	{
		dest = malloc(sizeof(char) * (len + 1));
		if (dest == NULL)
			return (NULL);
		token->quotes = 2;
		token->str = ft_strdup(strncpy(dest, input, len));
	}
	free(dest);
	return (token);
}

int	get_token_len(char *s, int len, int flag)
{
	t_direction	type;

	while (s[++len] && s[len] != ' ' && flag == -1)
	{
		type = basic_redirect_token_type(&s[len]);
		if (type != NO_REDIR)
			flag = len;
		if (s[len] == '|')
			return (len + 1);
		if (s[len + 1] == '|' && s[len + 2] != '\'' && s[len + 2] != '\"')
			break ; /* 이 부분이 살짝 다름 */
		else if (s[len] == '\'' || s[len] == '\"')
		{
			len += get_end_quote(&s[len + 1], s[len]) + 1;
			if (s[len + 1] == '|')
				return (len + 1);
		}
	}
	if (flag != -1)
		len = get_token_len_with_redirect(flag, type);
	return (len);
}

t_token_list	*get_token_list(char *input)
{
	int				len;
	t_token_list	*token;

	input += jump_space(input);
	if (*input == NULL)
		return (NULL);
	len = get_token_len(input, -1, -1);
	token = get_token(input, len); /* 에러 처리 필요 */
	token->next = get_token_list(input + len);
	return (token);
}
