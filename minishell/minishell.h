/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:41:47 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/16 13:34:08 by yeongele         ###   ########.fr       */
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
	struct s_token_list					*next;
}	t_token_list;

typedef struct s_redirect_list
{
	t_direction							direction;
	char								*file;
	struct s_redirect_list				*next;
}	t_redirect_list;

typedef struct s_parsed_cmd
{
	int									is_pipe;
	t_token_list						*arg;
	t_redirect_list						*redirection;
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

/*					builtins				*/
int						find_line(char *str);
void					error_redirection(char *file, int err_type);
void					error_exit(char	*s, int err_type);

/*					exec				*/
void					heredoc_signal(int sig);
void					ctrl_d(char	*line);
void					ctrl_c(int sig);
void					check_signal(void);
int						single_cmd(t_p_cmd_managed_list *managed);

/*					parsing				*/
char					*before_dollar(char *s);
void					after_dollar(char *s, int *i);
void					*set_env(t_token_list *token_list);
char					*get_env_value(char *s);
int						*open_files(t_redirect_list *redirect_list);
t_p_cmd_managed_list	*create_p_cmd_managed_list(t_p_cmd_list *cmdline);
t_p_cmd_managed_list	*parse(char *input);
int						get_quote_len(char *input, int flag);
int						get_end_quote(char *s, int c);
int						quotes(char *s);
int						empty(char *s);
int						is_pipe(t_token_list *token, t_p_cmd *parsed_cmd);
int						check_syntax(t_token_list *token_list);
t_token_list			*get_token_list(char *input);

/*					utils		*/
void					init_env(char **env);
int						jump_space(char	*input);
void					copy_env_value(char *s, int i);
void					set_env_return(char **new, char *s, int *i, int *len);
void					set_env_return_len(char *s, int *i, int *len);
void					free_square(char *square);
int						free_token_list(t_token_list *token_list);
void					free_p_cmd_list(t_p_cmd_list *p_cmd_list);
void					free_p_cmd_managed_list(
							t_p_cmd_managed_list *p_cmd_managed_list);
t_p_cmd					*init_parsed_cmd(void);
void					init_struct(t_token_list **token_head,
							t_token_list **token_list,
							t_p_cmd **parsed_cmd,
							t_p_cmd_list **parsed_cmd_list);
int						find_quote(char *s, int len);
char					*remove_quote(char *input, char *dest, int flag);
int						help_quote1(char *input, int *i, int *len);
int						help_quote2(char *input, char *dest, int *i, int *len);
int						ft_strcmp(char *s1, char *s2);
int						ft_strhei(char **square);
int						ft_isnumeric(char *s);
int						get_token_len_with_redirect(int flag, t_direction type);
int						basic_redirect_token_type(char *s);
int						redirect_token_type(char *s, t_token_list *token);

#endif