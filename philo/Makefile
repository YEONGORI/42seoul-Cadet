# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 10:52:33 by yeongele          #+#    #+#              #
#    Updated: 2023/04/08 14:45:00 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  philo
CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread #-g -fsanitize=thread 

SRCS = philo.c utils.c init.c action1.c action2.c

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
