# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/01/20 10:31:49 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME = fdf

SRCS = srcs/main.c srcs/ft_check_stock.c srcs/ft_list.c srcs/ft_draw.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror -g

##################
##    COLORS    ##
##################

_GREY	=$ \033[30m
_RED	=$ \033[31m
_GREEN	=$ \033[32m
_YELLOW	=$ \033[33m
_BLUE	=$ \033[34m
_PURPLE	=$ \033[35m
_CYAN	=$ \033[36m
_WHITE	=$ \033[37m
_END	=$ \033[0m

##################
##   TARGETS    ##
##################

.PHONY: all clean

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C libft
	@gcc $(FLAGS) -lmlx -framework OpenGL -framework Appkit $(OBJ) ./libft/libft.a -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@echo $@

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all
