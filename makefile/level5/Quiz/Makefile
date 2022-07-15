NAME:=libft.a

AR:=ar

ARFLAG:=rcs

SRCS:=first.c second.c third.c

OBJS:=$(SRCS:.c=.o)

CC := gcc

CFLAGS := -Wall -Wextra -Werror

$(NAME):$(OBJS)
	$(AR) $(ARFLAG) $@ $<

$(suffix $(SRCS))

%.o:%.c
	$(CC) $(CFLAGS) -c $<