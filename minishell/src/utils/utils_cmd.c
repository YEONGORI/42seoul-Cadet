/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 23:13:15 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 19:16:38 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*create_cmd(void)
{
	t_cmd	*parsed_cmd;

	parsed_cmd = (t_cmd *)malloc(sizeof(t_cmd));
	parsed_cmd->argu = (t_token_list *)(NULL);
	parsed_cmd->redirections = (t_redirection_list *)(NULL);
	parsed_cmd->is_piped = 0;
	return (parsed_cmd);
}
