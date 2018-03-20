# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 12:18:12 by lguiller          #+#    #+#              #
#    Updated: 2018/03/16 14:38:18 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##################
##  VARIABLES   ##
##################

NAME			= fdf
SRCS			= main.c ft_check_stock.c ft_list.c ft_draw.c \
				  event_functions.c ft_pixels.c octan_part_one.c \
				  octan_part_two.c octan_part_three.c octan_part_four.c \
				  auto_function.c
INCLUDES		= ./includes/
LIBFT			= ./libft/libft.a
MINILIBX		= ./minilibx/libmlx.a
OBJ				= $(addprefix ./srcs/, $(SRCS:.c=.o))
FLAGS			= -Wall -Wextra -Werror -O3
FRAMEWORK		= -framework OpenGL -framework Appkit

##################
##    COLORS    ##
##################

_BLACK	= "\033[30m"
_RED	= "\033[31m"
_GREEN	= "\033[32m"
_YELLOW	= "\033[33m"
_BLUE	= "\033[34m"
_VIOLET	= "\033[35m"
_CYAN	= "\033[36m"
_WHITE	= "\033[37m"
_END	= "\033[0m"
_CLEAR	= "\033[2K"
_UP		= "\033[A"
_CUT	= "\033[k"

##################
##   TARGETS    ##
##################

.PHONY: all libft minilibx clean fclean re

all: libft minilibx $(NAME)

libft:
	@make -C libft

minilibx:
	@make -C minilibx

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(FRAMEWORK) $(MINILIBX) $(OBJ) $(LIBFT) -o $(NAME)
	@echo $(_GREEN)"Done."$(_END)

%.o: %.c
	@gcc $(FLAGS) -I $(INCLUDES) -c $^ -o $@
	@printf $(_YELLOW)"building - "$(_GREEN)
	@printf $@ | cut -c3- | cut -d'.' -f1
	@printf $(_END)

clean:
	@make -C libft clean
	@make -C minilibx clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all

lynux:
	@make -C libft lynux

booh:
	@make -C libft booh
