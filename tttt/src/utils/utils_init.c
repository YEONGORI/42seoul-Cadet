/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:45:07 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 23:09:29 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_env(char **env)
{
	int	i;

	i = -1;
	g_env.env = malloc(sizeof(char *) * (ft_strhei(env) + 1));
	while (env[++i])
		g_env.env[i] = ft_strdup(env[i]);
	g_env.env[i] = NULL;
}

t_cmd	*init_parsed_cmd(void)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->argu = (t_token_list *)(NULL);
	cmd->redirections = (t_token_list *)(NULL);
	cmd->is_piped = 0;
	return (cmd);
}

void	init_struct(t_token_list **token_head,
						t_token_list **token_list,
						t_cmd **cmd,
						t_cmdline **cmd_list)
{
	*token_head = *token_list;
	*cmd = init_parsed_cmd();
	*cmd_list = NULL;
}
