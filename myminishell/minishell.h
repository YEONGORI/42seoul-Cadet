/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:41:47 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/12 12:58:01 by yeongele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <unistd.h>

typedef enum s_direction
{
	INPUT_FILE,
	INPUT_NEXT_LINE,
	OUTPUT_FILE_CREATE,
	OUTPUT_FILE_APPEND,
	NO_REDIR
}	t_direction;

typedef struct s_env
{
	char								**env;
	char								**path;
	int									ret_exit;
	int									cmd_not_found;
	int									*is_exit;
	int									heredoc_signal;
	struct stat							*stat;
}	t_env;

typedef struct s_token_list
{
	char								*str;
	int									quotes;
	struct s_string_list				*next;
}	t_token_list;

typedef strcut s_redirect_list
{
	t_direction							direction;
	char								*file;
	struct s_redirect_list				*next;
}	t_redirection_list;

typedef struct s_parsed_cmd
{
	int									is_pipe;
	t_token_list						*arg;
	t_redirection_list					*redirections;
}	t_p_cmd;

typedef struct s_parsed_cmd_list
{
	t_p_cmd								*cmd;
	struct s_parsed_cmd_list			*next;
}	t_p_cmd_list;

typedef struct s_parsed_cmd_managed
{
	char								**av;
	int									ac;
	int									in_desc;
	int									out_desc;
	int									is_pipe;
}	t_p_cmd_managed;

typedef struct s_parsed_cmd_managed_list
{
	t_p_cmd_managed						*cmd;
	pid_t								pid;
	int									fd[2];
	struct s_parsed_cmd_managed_list	*next;
	struct s_parsed_cmd_managed_list	*prev;
}	t_p_cmd_managed_list;

t_env 									g_env;

/*					exec				*/
void					ctrl_d(char	*line);
void					ctrl_c(int sig);
void					check_signal(void);

/*					init				*/
void					init_env(char **env);

/*					parsing				*/
t_p_cmd_managed_list	*parse(char *input);

int						quotes(char *s);
int						empty(char *s);

t_token_list			*get_token_list(char *input);

/*					utils				*/
int						jump_space(char	*input);


int						ft_strhei(char **square);
void					free_square(char *square);

#endif