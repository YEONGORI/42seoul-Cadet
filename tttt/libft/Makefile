# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 18:50:04 by yeongele          #+#    #+#              #
#    Updated: 2023/05/16 22:49:05 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c ft_putchar_fd.c ft_putstr_fd.c ft_strcmp.c ft_strdup.c ft_strlen.c ft_strncmp.c ft_strjoin.c ft_itoa.c ft_bzero.c ft_calloc.c ft_strchr.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rsc $@ ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -c ${SRCS}

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re