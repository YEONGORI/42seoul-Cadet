CC=gcc
CFLAGS=-Wall -Wextra -Werror
OBJS=tester.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o ft_strlcat.o ft_strchr.o ft_strrchr.o ft_toupper.o ft_tolower.o ft_strncmp.o ft_memchr.o ft_memcmp.o
TARGET=tester

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

tester.o: tester.h tester.c

ft_isalpha.o: tester.h ft_isalpha.c

ft_isdigit.o: tester.h ft_isdigit.c

ft_isalnum.o: tester.h ft_isalnum.c

ft_isascii.o: tester.h ft_isascii.c

ft_isprint.o: tester.h ft_isprint.c

ft_strlen.o: tester.h ft_strlen.c

ft_memset.o: tester.h ft_memset.c

ft_bzero.o: tester.h ft_bzero.c

ft_memcpy.o: tester.h ft_memcpy.c

ft_memmove.o: tester.h ft_memmove.c

ft_strlcpy.o: tester.h ft_strlcpy.c

ft_strlcat.o: tester.h ft_strlcat.c

ft_toupper.o: tester.h ft_toupper.c

ft_tolower.o: tester.h ft_tolower.c

ft_strchr.o: tester.h ft_strchr.c

ft_strrchr.o: tester.h ft_strrchr.c

ft_strncmp.o: tester.h ft_strncmp.c

ft_memchr.o: tester.h ft_memchr.c

ft_memcmp.o: tester.h ft_memcmp.c