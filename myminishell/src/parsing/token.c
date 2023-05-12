/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:52 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/12 13:03:15 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token_list	*get_token(char *input, int len)
{
	
}

int	get_token_len(char *s, int len, int flag)
{
	t_direction	type;

	while (s[len] && s[len] != ' ' && flag == -1)
	{
		type = 
	}
}

t_token_list	*get_token_list(char *input)
{
	int				len;
	t_token_list	*token;

	input += jump_space(input);
	if (*input == NULL)
		return (NULL);
	len = get_token_len(input, 0, -1);
	token = get_token(input, len);
	token->next = get_token_list(input + len);
	return (token);
}
