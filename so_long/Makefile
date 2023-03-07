# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/03/07 10:19:48 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC       = cc
# CFLAGS   = -Wall -Werror -Wextra
# NAME     = so_long

# GNG_DIR  = ./get_next_line
# LIBFT_DIR= ./libft
# INC_DIRS = -I$(GNL_DIR) -I$(LIBFT_DIR)

# SRC      = so_long.c map.c map_checker.c map_parser.c \
#            $(GNG_DIR)/get_next_line.c $(GNG_DIR)/get_next_line_utils.c \
#            $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strdup.c
# OBJ      = $(SRC:.c=.o)

# MLX_DIR  = mlx
# MLX_LIB  = $(MLX_DIR)/libmlx.a
# MLX_LNK  = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# SUBDIRS  = $(MLX_DIR)

# all: $(SUBDIRS) $(NAME)

# $(SUBDIRS):
# 	$(MAKE) -C $@

# $(NAME): $(OBJ) $(MLX_LIB)
# 	$(CC) $(CFLAGS) $(OBJ) $(MLX_LNK) -o $(NAME)

# $(MLX_LIB):
# 	$(MAKE) -C $(MLX_DIR)

# clean:
# 	$(MAKE) -C $(MLX_DIR) clean
# 	rm -rf $(OBJ)

# fclean: clean
# 	$(MAKE) -C $(MLX_DIR) clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re $(SUBDIRS)

CC		= cc
CFLAGS	= 
MLX		= -L mlx -lmlx -framework OpenGL -framework AppKit
NAME	= so_long

GNG_DIR = ./get_next_line
LIBFT_DIR = ./libft
INC_DIRS = -I$(GNL_DIR) -I

SRC		= so_long.c map.c map_checker.c map_parser.c key.c key_checker.c key_move.c algorithm.c queue.c utils.c\
		  $(GNG_DIR)/get_next_line.c $(GNG_DIR)/get_next_line_utils.c \
		  $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_itoa.c
OBJ		= $(SRC:.c=.o)

all: $(OBJ) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME) 

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re