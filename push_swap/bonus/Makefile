# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/05/15 10:13:08 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= checker

SRC		= push_swap_bonus.c \
		operations/push_bonus.c operations/rev_rotate_bonus.c operations/rotate_bonus.c operations/swap_bonus.c \
		utils/checker_bonus.c utils/init_bonus.c utils/utils_bonus.c \
		libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_strdup.c libft/ft_strlen.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
		
OBJ		= $(SRC:.c=.o)

all: $(OBJ) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re