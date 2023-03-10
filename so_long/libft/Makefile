NAME = libft.a

CC	 = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_itoa.c ft_split.c ft_strdup.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rsc $@ ${OBJS}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
