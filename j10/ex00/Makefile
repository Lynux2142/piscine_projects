# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 10:35:50 by lguiller          #+#    #+#              #
#    Updated: 2017/07/26 09:56:35 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
	   srcs/ft_strlen.c srcs/ft_swap.c

OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

HEADERS = ./includes

all: compil

$(OBJ):
	gcc -I $(HEADERS) -c $(SRCS)

compil: $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib libft.a

clean:
	rm -f *.o

fclean: clean
	rm -f libft.a

re: fclean all
