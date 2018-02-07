# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/02/05 17:51:57 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME = fdf

SRCS = srcs/main.c srcs/ft_check_stock.c srcs/ft_list.c srcs/ft_draw.c \
	   srcs/event_functions.c srcs/ft_pixels.c srcs/octan_part_one.c \
	   srcs/octan_part_two.c srcs/octan_part_three.c srcs/octan_part_four.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

##################
##    COLORS    ##
##################

_BLACK	=$ \033[30m
_RED	=$ \033[31m
_GREEN	=$ \033[32m
_YELLOW	=$ \033[33m
_BLUE	=$ \033[34m
_VIOLET	=$ \033[35m
_CYAN	=$ \033[36m
_WHITE	=$ \033[37m
_END	=$ \033[0m
_CLEAR	=$ \033[2K

##################
##   TARGETS    ##
##################

.PHONY: all libft clean

all: libft $(NAME)

libft:
	@make -C libft

$(NAME): $(OBJ)
	@gcc $(FLAGS) -lmlx -framework OpenGL -framework Appkit $(OBJ) ./libft/libft.a -o $(NAME)
	@printf "$(_GREEN) Done.\n$(_END)"

%.o: %.c
	@gcc $(FLAGS) -c $^ -o $@
	@printf "$(_YELLOW) building - $(_END)"
	@printf "$(_GREEN)"
	@printf $@ | cut -c6- | cut -d'.' -f1
	@printf "$(_END)"

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

lynux:
	@make -C libft lynux

booh:
	@make -C libft booh
