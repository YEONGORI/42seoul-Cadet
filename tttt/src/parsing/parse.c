/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:34:14 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 23:05:00 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd_managed_list	*parsing(char *input)
{
	t_token_list		*token_list;
	t_cmdline			*cmdline_list;
	t_cmd_managed_list	*cmd_managed_list;

	cmd_managed_list = NULL;
	token_list = create_token_list(input);
	if (token_list == NULL)
		return (NULL);
	set_env(token_list);
	if (!check_syntax(token_list) && free_token_list(token_list))
		return (NULL);
	cmdline_list = create_cmdline_list(token_list);
	free_token_list(token_list);
	if (cmdline_list == NULL)
		return (NULL);
	// p_cmd_managed_list = create_p_cmd_managed_list(p_cmd_list);
	// free_p_cmd_list(p_cmd_list);
	// if (exit_condition(p_cmd_managed_list)
	// 	&& !p_cmd_managed_list->next)
	// {
	// 	execute_exit(p_cmd_managed_list);
	// 	free_p_cmd_managed_list(p_cmd_managed_list);
	// 	return (NULL);
	// }
	// return (p_cmd_managed_list);
	return (cmd_managed_list);
}
