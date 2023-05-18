/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:28:01 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 11:12:34 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	env(void)
{
	int	i;

	i = 0;
	while (g_env.env[i])
		ft_putendl_fd(g_env.env[i++], 1);
	g_env.ret_exit = 0;
}
