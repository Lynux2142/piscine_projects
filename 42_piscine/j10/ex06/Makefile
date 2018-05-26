# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 09:35:41 by lguiller          #+#    #+#              #
#    Updated: 2017/07/25 17:44:55 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRC = ft_atoi.c ft_calc.c ft_print_result.c main.c

OBJ = ft_atoi.o ft_calc.o ft_print_result.o main.o

all: $(NAME)

$(OBJ):
	gcc -c $(SRC)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	rm ft_atoi.o ft_calc.o ft_print_result.o main.o

fclean: clean
	rm $(NAME)

re: fclean all
