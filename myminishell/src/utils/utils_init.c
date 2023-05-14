/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:45:07 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 20:29:54 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_p_cmd	*init_parsed_cmd(void)
{
	t_p_cmd	*p_cmd;

	p_cmd = (t_p_cmd *)malloc(sizeof(t_p_cmd));
	p_cmd->arg = (t_token_list *)(NULL);
	p_cmd->redirection = (t_token_list *)(NULL);
	p_cmd->is_pipe = 0;
	return (p_cmd);
}

void	init_struct(t_token_list **token_head,
						t_token_list **token_list,
						t_p_cmd **parsed_cmd,
						t_p_cmd_list **parsed_cmd_list)
{
	*token_head = *token_list;
	*parsed_cmd = init_parsed_cmd();
	*parsed_cmd_list = NULL;
}
