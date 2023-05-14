/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:34:14 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 20:22:20 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_p_cmd_managed_list	*parse(char *input)
{
	t_token_list			*token_list;
	t_p_cmd_list			*p_cmd_list;
	t_p_cmd_managed_list	*p_cmd_managed_list;

	p_cmd_managed_list = NULL;
	token_list = get_token_list(input);
	if (token_list == NULL)
		return (NULL);
	set_env(token_list);
	if (!check_syntax(token_list) && free_token_list(token_list))
		return (NULL);
	p_cmd_list = create_p_cmd_list(token_list);
	free_token_list(token_list);
	if (p_cmd_list == NULL)
		return (NULL);
	p_cmd_managed_list = create_p_cmd_managed_list(p_cmd_list);
	
}
