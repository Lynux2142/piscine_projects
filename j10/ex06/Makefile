# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/24 09:35:41 by lguiller          #+#    #+#              #
#    Updated: 2017/07/26 09:55:58 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE_NAME = do-op

SRC = ft_atoi.c ft_calc.c ft_print_result.c main.c

OBJ = ft_atoi.o ft_calc.o ft_print_result.o main.o

all: compil

$(OBJ):
	gcc -c $(SRC)

compil: $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(EXE_NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXE_NAME)

re: fclean all
