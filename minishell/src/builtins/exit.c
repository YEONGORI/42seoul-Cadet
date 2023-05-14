/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:13:08 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 21:37:20 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_exit_pipe(t_p_cmd_managed_list *p_cmd_managed_list)
{
	int	i;

	while (p_cmd_managed_list)
	{
		i = -1;
		while (p_cmd_managed_list->cmd->av[0][++i])
			if (p_cmd_managed_list->cmd->av[0][i] == '|')
				return (1);
		p_cmd_managed_list = p_cmd_managed_list->next;
	}
	return (0);
}

int	check_exit_condition(t_p_cmd_managed_list *p_cmd_managed_list)
{
	if ((ft_strcmp(p_cmd_managed_list->cmd->av[0], "exit") == 0)
		&& !find_exit_pipe(p_cmd_managed_list))
		return (1);
	return (0);
}

void	execute_exit(t_p_cmd_managed_list *p_cmd_managed_list)
{
	int	exit_num;

	if (p_cmd_managed_list->cmd->av[1])
	{
		if (!ft_isnumeric(p_cmd_managed_list->cmd->av[1]))
			error_exit(p_cmd_managed_list->cmd->av[1], 2);
		if (p_cmd_managed_list->cmd->av[2])
		{
			error_exit(NULL, 1);
			return ;
		}
		exit_num = ft_atoi(p_cmd_managed_list->cmd->av[0]);
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
