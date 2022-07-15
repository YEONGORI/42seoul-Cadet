NAME:=libft.a
AR:=ar
ARFLAG:=rcs
CC:=cc
CFLAGS:=-Wall -Wextra -Werror
SRCS:=first.c second.c third.c
OBJS:=$(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(AR) $(ARFLAG) $@ $<

%.o:%.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -r *.o

fclean:clean
	rm -rf *.a

re: fclean all

.PHONY : all clean fclean