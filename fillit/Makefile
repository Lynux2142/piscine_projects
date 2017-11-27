# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:15:29 by lguiller          #+#    #+#              #
#    Updated: 2017/11/27 17:39:56 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME	= fillit

SRC 	= srcs/main.c srcs/ft_stock_and_check_file.c \
		  srcs/ft_split_rec_tetri.c srcs/ft_nb.c \
		  srcs/ft_solve_grid.c

FLAGS 	= -Wall -Wextra -Werror

##################
##    COLORS    ##
##################

_GREY	=	$ \033[30m
_RED	=	$ \033[31m
_GREEN	=	$ \033[32m
_YELLOW	=	$ \033[33m
_BLUE	=	$ \033[34m
_PURPLE	=	$ \033[35m
_CYAN	=	$ \033[36m
_WHITE	=	$ \033[37m
_END	=	$ \033[0m

##################
##   TARGETS    ##
##################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(_GREEN)Creation de libft.a	😎$(_END)"
	@make -C libft all
	@echo "$(_GREEN)Creation de fillit	😎$(_END)"
	@gcc $(FLAGS) ./libft/libft.a $(SRC) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@

clean:
	@echo "$(_RED)Suppression des *.o	😱$(_END)"
	@make -C libft clean

fclean: clean
	@echo "$(_RED)Suppression de libft.a	😱$(_END)"
	@make -C libft fclean
	@echo "$(_RED)Suppression de fillit	😱$(_END)"
	@/bin/rm -f $(NAME)

re: fclean all
