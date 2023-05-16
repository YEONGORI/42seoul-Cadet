/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:28:07 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 13:20:37 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*check_dir(char *argu)
{
	char	*dir;

	if (argu == NULL || ft_strcmp(argu, "~" == 0))
		dir = get_env_value("$HOME");
	else if (ft_strcmp(argu, "-") == 0)
	{
		dir = get_env_value("$OLDPWD");
		ft_putstr_fd(dir, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		dir = ft_strdup(argu);
	return (dir);
}

void	set_pwd_and_oldpwd(char *oldpwd, char *dir)
{
	char	**new_env;

	if (ft_strcmp(dir, "."))
	{
		new_env = set_env("OLDPWD", oldpwd);
		free(oldpwd);
		oldpwd = getcwd(NULL, 0);
		free_square(g_env.env);
		init_env(new_env);
		free_square(new_env);
		new_env = set_env("PWD", oldpwd);
		free_square(g_env.env);
		init_env(new_env);
		free_square(new_env);
	}
	g_env.ret_exit = 0;
	free(oldpwd);
	free(dir);
}

int	ch(char *argu)
{
	char	*dir;
	char	*oldpwd;

	dir = check_dir(argu);
	oldpwd = NULL;
	if (access(dir, F_OK) == -1)
	{
		error_cd(dir, 1);
		return (1);
	}
	if (access(dir, R_OK) == -1)
	{
		error_cd(dir, 2);
		return (1);
	}
	oldpwd = getcwd(NULL, 0);
	if (chdir(dir) == -1)
	{
		error_cd(dir, 3);
		free(oldpwd);
		return (1);
	}
	set_pwd_and_oldpwd(oldpwd, dir);
	return (0);
}
