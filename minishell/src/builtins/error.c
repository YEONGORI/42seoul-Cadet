/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:41:15 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 13:16:05 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	error_redirection(char *file, int err_type)
{
	if (err_type == 1)
	{
		ft_putstr_fd("$: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
}

void	error_cd(char *file, int err_type)
{
	if (err_type == 1)
	{
		ft_putstr_fd("$ cd: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (err_type == 2)
	{
		ft_putstr_fd("$: cd: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	if (err_type == 3)
	{
		ft_putstr_fd("$: cd: ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": Not a directory\n", 2);
	}
	g_env.ret_exit = 1;
	free(file);
}

void	error_exit(char	*s, int err_type)
{
	if (err_type == 1)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("$: exit: too many arguments\n", 2);
		g_env.ret_exit = 1;
	}
	else if (err_type == 2)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("$: exit: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit(255);
	}
}
