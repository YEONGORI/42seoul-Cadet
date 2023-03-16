NAME = libgnl.a

CC	 = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $^ -o $@

${NAME}: ${OBJS}
	ar rsc $@ ${OBJS}

clean:
	@rm -f ${OBJS}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
