/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:48:58 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/12 11:56:29 by yeongele         ###   ########.fr       */
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
