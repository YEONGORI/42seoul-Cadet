# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/05/15 20:41:24 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
# NAME	= push_swap

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PREF_M 	= mandatory/
PREF_B	= bonus/

SRC_M	= main.c \
		operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c \
		sort/sort.c sort/move.c sort/position.c sort/resolve.c\
		utils/checker.c utils/init.c utils/utils.c

SRC_B	= push_swap_bonus.c \
		operations/push_bonus.c operations/rev_rotate_bonus.c operations/rotate_bonus.c operations/swap_bonus.c \
		utils/checker_bonus.c utils/init_bonus.c utils/utils_bonus.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_M	= $(addprefix $(PREF_M), $(SRC_M))
SRCS_B	= $(addprefix $(PREF_B), $(SRC_B))

OBJS_M	= $(SRCS_M:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

ifdef FLAG
	NAME = checker
	OBJS_TOTAL = $(OBJS_B)
else
	NAME = push_swap
	OBJS_TOTAL = $(OBJS_M)
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_TOTAL)
	$(CC) $(CFLAGS) $(OBJS_TOTAL) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	@make FLAG=1 all

clean:
	@rm -rf $(OBJS_M)
	@rm -rf $(OBJS_B)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f checker
	@rm -f push_swap
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus