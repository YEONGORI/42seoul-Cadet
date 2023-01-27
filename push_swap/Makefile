# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/01/27 21:46:00 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= push_swap

SRC		= main.c \
		libft/ft_lstadd_back.c libft/ft_lstadd_front.c libft/ft_lstclear.c libft/ft_lstdelone.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_strcmp.c libft/ft_strdup.c libft/ft_strlen.c \
		operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c \
		sort/sort.c sort/move.c sort/position.c sort/resolve.c\
		utils/checker.c utils/init.c utils/utils.c
		
OBJ		= $(SRC:.c=.o)
INCS	= -I

all: $(OBJ) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf *.o
	@rm -rf libft/*.o
	@rm -rf operations/*.o
	@rm -rf sort/*.o
	@rm -rf utils/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

# test2:				$(NAME)	
# 					$(eval ARG = $(shell shuf -i 0-100 -n 2))
# 					./push_swap $(ARG) | ./checker_linux $(ARG)
# 					@echo -n "Instructions: "
# 					@./push_swap $(ARG) | wc -l

# test3:				$(NAME)	
# 					$(eval ARG = $(shell shuf -i 0-100 -n 3))
# 					./push_swap $(ARG) | ./checker_linux $(ARG)
# 					@echo -n "Instructions: "
# 					@./push_swap $(ARG) | wc -l

# test5:				$(NAME)	
# 					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
# 					./push_swap $(ARG) | ./checker_linux $(ARG)
# 					@echo -n "Instructions: "
# 					@./push_swap $(ARG) | wc -l

# test100:			$(NAME)	
# 					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
# 					./push_swap $(ARG) | ./checker_linux $(ARG)
# 					@echo -n "Instructions: "
# 					@./push_swap $(ARG) | wc -l

# test500:			$(NAME)	
# 					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
# 					./push_swap $(ARG) | ./checker_linux $(ARG)
# 					@echo -n "Instructions: "
# 					@./push_swap $(ARG) | wc -l

# test1000:			$(NAME)	
# 					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
# 					./push_swap $(ARG) | ./checker_linux $(ARG)
# 					@echo -n "Instructions: "
# 					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000