# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/05/15 13:41:19 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= checker

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC		= push_swap_bonus.c \
		operations/push_bonus.c operations/rev_rotate_bonus.c operations/rotate_bonus.c operations/swap_bonus.c \
		utils/checker_bonus.c utils/init_bonus.c utils/utils_bonus.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
		
OBJ		= $(SRC:.c=.o)

all: $(OBJ) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re