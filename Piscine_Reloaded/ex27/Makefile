# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:35:51 by lguiller          #+#    #+#              #
#    Updated: 2017/11/08 16:44:22 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = srcs/ft_display_file.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c
OBJ = ft_display_file.o ft_putchar.o ft_putstr.o ft_strlen.o
HEADERS = ./includes
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -I $(HEADERS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(wildcard *.o)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
