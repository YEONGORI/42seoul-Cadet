NAME:=main
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
OBJ_DIR:=./obj/
SRC_DIR:=./src/
INC_DIR:=./include
OBJS:=$(addprefix $(OBJ_DIR),main.o fourth.o)
SRCS:=$(addprefix $(SRC_DIR),main.c fourth.c)

LIB_DIR:=./lib/
LIB:=libft.h
LIB_INC=$(LIB_DIR)lib/libft.a

all:$(NAME)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all

run:all
	./$(NAME)

$(NAME):$(OBJS) $(LIB)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I./lib -L$(LIB_DIR) -o $@ $^

$(LIB):
	make -C $(LIB_DIR) all

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -I./lib -c $^ -o $@