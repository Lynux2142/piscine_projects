# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2017/11/23 12:18:27 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_EXE = fillit

NAME_H = fillit.a

SRC = srcs/main.c srcs/ft_stock_file.c srcs/ft_check_norme.c \
	  srcs/ft_register_tetri.c srcs/ft_split_tetri.c srcs/ft_nb.c \

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME_H)

$(NAME_H): $(OBJ)
	@echo "Creation de libft.a"
	@make -C libft all
	@echo "Creation de fillit.a"
	@ar rc $(NAME_H) $(OBJ)
	@ranlib $(NAME_H)
	@echo "Creation de fillit"
	@gcc $(FLAGS) $(LIBFT) $(OBJ) -o $(NAME_EXE)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

clean:
	@echo "Suppression des *.o"
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "Suppression de libft.a, fillit.a et de fillit"
	@make -C libft fclean
	@/bin/rm -f $(NAME_EXE) $(NAME_H)

re: fclean all
