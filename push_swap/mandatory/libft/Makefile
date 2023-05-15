# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 18:50:04 by yeongele          #+#    #+#              #
#    Updated: 2023/05/15 13:33:14 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_lstadd_front.c ft_lstclear.c ft_lstnew.c ft_lstsize.c ft_strcmp.c ft_strdup.c ft_strlen.c \

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rsc $@ ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -c ${SRCS}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re