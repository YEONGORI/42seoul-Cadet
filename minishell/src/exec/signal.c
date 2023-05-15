/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:58:32 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 20:55:49 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	heredoc_signal(int sig)
{
	if (sig == SIGINT)
		g_env.heredoc_signal = 1;
}

void	ctrl_d(char	*line)
{
	if (!line)
	{
		write(1, "exit\n", 5);
		free(line);
		free_square(g_env);
		exit(EXIT_SUCCESS);
	}
}

void	ctrl_c(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	write(1, "\033[A", 3); // pin
	g_env.ret_exit = 1;
}

void	check_signal(void)
{
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}
