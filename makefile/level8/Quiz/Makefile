NAME:=main
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
SRCS:=$(addprefix ./src/,main.c first.c second.c third.c)
OBJS:=$(addprefix ./obj/,main.o first.o second.o third.o)
INCS:=./include

all:$(NAME)

run:all
	$(NAME)

clean:
	rm -f $(OBJS)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
./obj/%.o:./src/%.c
	@mkdir -p ./obj/
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@