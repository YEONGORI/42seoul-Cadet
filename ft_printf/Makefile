# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/14 18:50:04 by yeongele          #+#    #+#              #
#    Updated: 2022/07/29 16:17:17 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_PREF = ft_
SRC_NAME = printf.c helper.c print_char.c print_dec.c print_hex_low.c \
			print_hex_up.c print_int.c print_ptr.c print_str.c print_und.c
SRCS = $(addprefix $(SRC_PREF),$(SRC_NAME))
B_SRCS = ft_bonus.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

INCS = ft_printf.h

ifdef FLAG
	OBJS_TOTAL = $(OBJS) $(B_OBJS)
else
	OBJS_TOTAL = $(OBJS)
endif

all : $(NAME)
clean:
	@rm -f $(OBJS) $(B_OBJS)
fclean:	clean
	@rm -f $(NAME)
re: 
	make fclean
	make all
bonus:
	@make FLAG=1 all

$(NAME) : $(OBJS_TOTAL)
	ar rsc $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(INCS)

.PHONY:	all clean fclean re bonus