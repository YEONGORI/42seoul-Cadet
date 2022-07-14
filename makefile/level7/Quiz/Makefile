NAME:=main
LIB:=libft.a

AR:=ar
ARFLAG:=rcs
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

SRC:=main.c
OBJ:=$(SRC:.c=.o)

LIB_SRC:=first.c second.c third.c
LIB_OBJ:=$(LIB_SRC:.c=.o)

$(NAME):$(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^
$(LIB): $(LIB_OBJ)
	$(AR) $(ARFLAG) ft 