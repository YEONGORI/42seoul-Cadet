/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:13:08 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/17 20:21:36 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_exit_pipe(t_cmd_managed_list *cmd_managed_list)
{
	int	i;

	while (cmd_managed_list)
	{
		i = -1;
		while (cmd_managed_list->cmd->av[0][++i])
			if (cmd_managed_list->cmd->av[0][i] == '|')
				return (1);
		cmd_managed_list = cmd_managed_list->next;
	}
	return (0);
}

int	check_exit_condition(t_cmd_managed_list *cmd_managed_list)
{
	if ((ft_strcmp(cmd_managed_list->cmd->av[0], "exit") == 0)
		&& !find_exit_pipe(cmd_managed_list))
		return (1);
	return (0);
}

void	execute_exit(t_cmd_managed_list *cmd_managed_list)
{
	int	exit_num;

	if (cmd_managed_list->cmd->av[1])
	{
		if (!ft_isnumeric(cmd_managed_list->cmd->av[1]))
			error_exit(cmd_managed_list->cmd->av[1], 2);
		if (cmd_managed_list->cmd->av[2])
		{
			error_exit(NULL, 1);
			return ;
		}
		exit_num = ft_atoi(cmd_managed_list->cmd->av[0]);
		if (exit_num > 255)
			exit_num %= 256;
		ft_putstr_fd("exit\n", 1);
		exit(exit_num);
	}
	else
	{
		ft_putstr_fd("exit\n", 1);
		exit(g_env.ret_exit);
	}
}
