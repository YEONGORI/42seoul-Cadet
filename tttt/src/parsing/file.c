/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 20:32:27 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/14 20:58:28 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	output_file_create(t_redirect_list *redirection, int *fd)
{
	if (fd[1] != 0)
		close(fd[1]);
	fd[1] = open(redirection->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		error_redirection(redirection->file, 1);
}

void	output_file_append(t_redirect_list *redirection, int *fd)
{
	if (fd[1] != 0)
		close(fd[1]);
	fd[1] = open(redirection->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd[1] == -1)
		error_redirection(redirection->file, 1);
}

void	input_file(t_redirect_list *redirection, int *fd)
{
	if (fd[0] != 0)
		close(fd[0]);
	fd[0] = open(redirection->file, O_RDONLY);
	if (fd[0] == -1)
		error_redirection(redirection->file, 1);
}

void	heredoc(t_redirect_list *redirection, int *fd, int *fd_pipe, int pid)
{
	char	*line;

	if (fd[0] != 0)
		close(fd[0]);
	pipe(fd_pipe);
	pid = fork();
	if (pid == 0)
	{
		while (1)
		{
			signal(SIGINT, heredoc_signal);
			if (g_env.heredoc_signal == 1)
				exit(1);
			line = readline("> ");
			if (ft_strcmp(line, redirection->file) == 0)
			{
				free(line);
				exit(0);
			}
			ft_putstr_fd(line, fd_pipe[1]);
			ft_putstr_fd("\n", fd_pipe[1]);
			free(line);
		}
	}
	else
		waitpid(pid, &g_env.heredoc_signal, 0);
	close(fd_pipe[1]);
	fd[0] = fd_pipe[0];
}

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
	while (redirect_list)
	{
		if (redirect_list->direction == OUTPUT_FILE_CREATE)
			output_file_create(redirect_list, fd);
		else if (redirect_list->direction == OUTPUT_FILE_APPEND)
			output_file_append(redirect_list, fd);
		else if (redirect_list->direction == INPUT_FILE)
			input_file(redirect_list, fd);
		else if (redirect_list->direction == INPUT_NEXT_LINE)
			heredoc(redirect_list, fd, fd_pipe, pid);
		redirect_list = redirect_list->next;
	}
	free(fd_pipe);
	return (fd);
}
