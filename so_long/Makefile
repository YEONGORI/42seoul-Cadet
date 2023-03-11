# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/03/11 15:54:55 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME = so_long

GNL_DIR = gnl
GNL = -L$(GNL_DIR) -lgnl
LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

SRCS = so_long.c map.c map_checker.c map_parser.c \
key.c key_checker.c key_move.c algorithm.c queue.c utils.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re libft gnl

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): libft gnl $(OBJS)
ifdef $(NAME)
	$(CC) -o $@ $(OBJS) $(MLX) $(LIBFT) $(GNL)
else
	
endif

libft:
	make -C $(LIBFT_DIR)

gnl:
	make -C $(GNL_DIR)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean

re: fclean all