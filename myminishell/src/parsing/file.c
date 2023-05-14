/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:32:27 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 20:34:08 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	*open_files(t_redirect_list *redirect_list)
{
	int	pid;
	int	*fd;
	int	*fd_pipe;

	g_env.heredoc_signal = 0;
	fd = malloc(sizeof(int) * 2);
	fd_pipe = malloc(sizeof(int) * 2);
	pid = 0;
	fd[0] = 0;
	fd[1] = 0;
}