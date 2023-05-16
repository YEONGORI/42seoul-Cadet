# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 19:54:11 by yeongele          #+#    #+#              #
#    Updated: 2023/05/16 23:13:10 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= cc
FLAGS	= -Wall -Wextra -Werror

SRC_M = minishell.c \
		exec/signal.c \
		parsing/parse.c parsing/quotes.c parsing/dollar.c parsing/env.c parsing/token.c \
		utils/utils_init.c utils/utils_free.c utils/utils_str.c utils/utils_char.c utils/utils_env.c utils/utils_quote.c utils/utils_token.c utils/utils_cmd.c
SRCS = $(addprefix src/, $(SRC_M))
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) -lreadline

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean:	clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean
	all

bonus:
	@make FLAG=1 all
	
.PHONY:	all clean fclean re