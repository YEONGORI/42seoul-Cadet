# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/02/26 21:51:35 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
MLX		= -L mlx -lmlx -framework OpenGL -framework AppKit
NAME	= so_long

GNG_DIR = ./get_next_line
LIBFT_DIR = ./libft
INC_DIRS = -I$(GNL_DIR) -I

SRC		= so_long.c map.c map_checker.c \
		  $(GNG_DIR)/get_next_line.c $(GNG_DIR)/get_next_line_utils.c \
		  $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_strdup.c
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