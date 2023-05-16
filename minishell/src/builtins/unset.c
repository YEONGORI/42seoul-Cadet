/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:28:16 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 19:35:48 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_line(char *str)
{
	int		i;
	char	**split;

	i = 0;
	while (g_myenv.env[i])
	{
		split = ft_split(g_myenv.env[i], '=');
		if (ft_strcmp(split[0], str) == 0)
		{
			free_square(split);
			return (i);
		}
		free_square(split);
		i++;
	}
	return (-1);
}

char	**remove_line(char **arr, int line)
{
	int		i;
	int		j;
	char	**n_env;

	i = 0;
	j = 0;
	n_env = malloc(sizeof(char *) * (ft_strhei(g_env.env)));
	while (arr[i])
	{
		if (i != line)
			n_env[j++] = ft_strdup(arr[i]);
		i++;
	}
	n_env[j] = NULL;
	return (n_env);
}

void	unset(char **argu)
{
	int		i;
	int		line;
	char	**n_env;

	i = 1;
	while (argu[i])
	{
		line = find_line(argu[i]);
		if (line != -1)
		{
			n_env = remove_line(g_env.env, line);
			free_square(g_env.env);
			g_env.env = n_env;
			g_env.ret_exit = 0;
		}
		i++;
	}
	g_env.ret_exit = 0;
}
