# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/11 12:39:38 by lguiller          #+#    #+#              #
#    Updated: 2018/02/11 12:39:39 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = srcs/ft_display_file.c srcs/ft_putstr_fd.c srcs/ft_strlen.c
OBJ = $(SRC:.c=.o)
HEADERS = ./includes
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -I $(HEADERS) -c $^ -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
