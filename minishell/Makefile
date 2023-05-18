# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 19:54:11 by yeongele          #+#    #+#              #
#    Updated: 2023/05/18 09:49:00 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
FLAGS	= -Wall -Wextra -Werror

SRC_M = minishell.c \
		exec/exec.c exec/signal.c exec/path.c exec/single.c \
		builtins/error.c builtins/exit.c builtins/cd.c builtins/echo.c builtins/env.c builtins/export.c builtins/pwd.c builtins/unset.c \
		parsing/parse.c parsing/quotes.c parsing/dollar.c parsing/env.c parsing/token.c parsing/file.c parsing/manage.c parsing/cmd.c parsing/syntax.c \
		utils/utils.c utils/utils_init.c utils/utils_free.c utils/utils_str.c utils/utils_char.c utils/utils_env.c utils/utils_quote.c utils/utils_token.c utils/utils_cmd.c utils/utils_exec.c
SRCS = $(addprefix src/, $(SRC_M))
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME) : $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean
	make all

bonus:
	@make FLAG=1 all
	
.PHONY:	all clean fclean re