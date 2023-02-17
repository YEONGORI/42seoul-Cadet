# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeongele <yeongele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 14:04:28 by yeongele          #+#    #+#              #
#    Updated: 2023/02/16 17:02:18 by yeongele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME	= server
NAME2	= client
SRC		= ft_server.c ft_putnbr.c
SRC2	= ft_client.c ft_atoi.c
		
OBJ		= $(SRC:.c=.o)
OBJ2	= $(SRC2:.c=.o)

all: $(OBJ) $(NAME) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME2): ${OBJ2}
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ2)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)

re: fclean all

.PHONY: all clean fclean re