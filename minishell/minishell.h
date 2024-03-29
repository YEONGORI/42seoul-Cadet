/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ji-song <ji-song@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:02:07 by yeongele          #+#    #+#             */
/*   Updated: 2023/05/18 21:13:53 by ji-song          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

# include <stdint.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef enum s_redirection
{
	INPUT_FILE,
	INPUT_NEXT_LINE,
	OUTPUT_FILE_CREATE,
	OUTPUT_FILE_APPEND,
	NO_REDIR
}	t_redirection;

typedef struct s_env
{
	char			**env;
	char			**path;
	int				ret_exit;
	int				cmd_not_found;
	int				*is_exit;
	int				heredoc_signal;
	struct stat		*stat;
}	t_env;

typedef struct s_redirection_list
{
	t_redirection				red;
	char						*file;
	struct s_redirection_list	*next;
}	t_redirection_list;

typedef struct s_token_list
{
	char					*str;
	int						quotes;
	struct s_token_list		*next;
}	t_token_list;

typedef struct s_cmd
{
	int					is_piped;
	t_token_list		*argu;
	t_redirection_list	*redirections;
}	t_cmd;

typedef struct s_cmdline
{
	t_cmd				*cmd;
	struct s_cmdline	*next;
}	t_cmdline;

typedef struct s_cmd_managed
{
	char	**av;
	int		ac;
	int		in_desc;
	int		out_desc;
	int		is_piped;
}	t_cmd_managed;

typedef struct s_cmd_managed_list
{
	t_cmd_managed				*cmd;
	pid_t						pid;
	int							fd[2];
	struct s_cmd_managed_list	*next;
	struct s_cmd_managed_list	*prev;
}	t_cmd_managed_list;

t_env	g_env;

/*					builtins		*/
void				error_command(char *cmd, int err_type);
void				error_redirection(char *file, int err_type);
void				error_exit(char	*s, int err_type);
void				error_cd(char *file, int err_type);
int					check_exit_condition(t_cmd_managed_list *cmd_managed_list);
void				execute_exit(t_cmd_managed_list *cmd_managed_list);
void				pwd(void);
void				export(char **argu);
int					find_line(char *str);
void				unset(char **argu);
void				env(void);

/*					parsing			*/
int					ch_quotes(char *input);
int					ch_empty(char *input);
t_cmd_managed_list	*parsing(char *input);
t_token_list		*create_token_list(char *input);
int					get_quotation_len(char *s, int c);
int					get_only_quotation_len(char *input, int flag);
void				set_env(t_token_list *token);
char				*before_dollar(char *s);
void				after_dollar(char *s, int *i);
int					check_syntax(t_token_list *token);
int					is_pipe(t_token_list *token, t_cmd *cmd);
int					more_than_one_pipe(t_token_list *token_list);
t_cmdline			*create_cmd_list(t_token_list *token_list);
t_cmd_managed_list	*create_cmd_managed_list(t_cmdline *cmdline);
int					*open_files(t_redirection_list *redirect_list);
void				append_redir_list(t_redirection_list **redir,
						char *file, int type);
char				*get_env(char *s, int len, int is_env);
char				**set_export_env(char *env_name, char *value);

/*					exec			*/
void				ch_signal(void);
void				ctrl_d(char	*line);
void				ctrl_c(int sig);
int					single_cmd(t_cmd_managed_list *managed);
void				heredoc_signal(int sig);
void				execution(t_cmd_managed_list *list);
void				echo(char **argu);
int					cd(char *argu);
void				get_path(t_cmd_managed_list *parse);
char				*path_finder(char *cmd);
int					redirection_cmd(t_cmd_managed_list *managed);
int					is_builtin_cmd(char	*cmd);
void				exec_builtin(t_cmd_managed_list *managed, char *cmd);

/*					utils			*/
void				init_env(char **env);
void				init_struct(t_token_list **token_head,
						t_token_list **token_list,
						t_cmd **cmd,
						t_cmdline **cmd_list);
int					ft_strhei(char **square);
void				free_square(char **square);
int					free_token_list(t_token_list *token_list);
void				free_cmd_list(t_cmdline *cmd_list);
void				free_cmd_managed_list(t_cmd_managed_list *cmd_managed_list);
int					escape_space(char *input);
int					get_redirection_token_type(char *s);
int					redirection_token_type(char *s, t_token_list *token);
int					token_len(int flag, t_redirection type);
int					find_quote(char *s, int len);
int					help_quote1(char *input, int *i, int *j);
int					help_quote2(char *input, char *dest, int *i, int *len);
char				*copy_only_quotation(char *input, char *dest, int flag);
void				create_env_return(char **new, char *s, int *i, int *len);
void				copy_env_value(char *s, int i);
int					jump_space(char	*input);
t_cmd				*create_cmd(void);
t_cmdline			*create_cmd_list(t_token_list *token_list);
void				free_with_exit(char *s);
int					ft_isnumeric(char *s);
void				close_files(t_cmd_managed_list *list);
char				*ft_strncopy(char *dest, char *src, int n);

/*						libft			*/
int					ft_isdigit(int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoin_free(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_itoa(int n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_atoi(const char *str);
void				ft_putendl_fd(char *s, int fd);
char				**ft_split(const char *s, char c);
char				*path_finish(char *path, char *cmd);
#endif