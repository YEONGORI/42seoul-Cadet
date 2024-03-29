# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/05/15 13:40:52 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME = so_long

GNL_DIR = gnl
GNL = $(GNL_DIR)/libgnl.a


SRCS_M = so_long.c map.c map_checker.c map_parser.c key.c key_checker.c key_move.c algorithm.c queue.c utils.c
SRCS_B = so_long.c map.c map_checker.c map_parser.c key.c key_checker.c key_move_bonus.c algorithm.c queue.c utils.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

INCS = so_long.h
ifdef FLAG
	OBJS = $(OBJS_B)
else
	OBJS = $(OBJS_M)
endif

all: $(NAME)

$(NAME): $(LIBFT) $(GNL) $(OBJS)
	$(CC) -o $@ $(OBJS) $(MLX) $(LIBFT) $(GNL)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I$(INCS)

$(LIBFT):
	make -C $(LIBFT_DIR)
$(GNL):
	make -C $(GNL_DIR)

bonus:
	@make FLAG=1 all

clean:
	@rm -rf $(OBJS_M)
	@rm -rf $(OBJS_B)
	@make -C $(LIBFT_DIR) clean
	@make -C $(GNL_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft gnl