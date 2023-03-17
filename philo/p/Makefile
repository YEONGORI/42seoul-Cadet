# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 13:47:13 by jihyukim          #+#    #+#              #
#    Updated: 2022/09/08 15:55:09 by jihyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  philo

CC = cc
CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread -g 

SRCS = main.c philo.c act.c utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

%.o :%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
