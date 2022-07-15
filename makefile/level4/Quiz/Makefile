NAME:=libft.a

AR:=ar

ARFLAGS:=rcs

SRCS:=first.c second.c third.c

OBJS:=first.o second.o third.o

$(NAME):$(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o:%.c
	$(CC) $(CFALGS) -c $<