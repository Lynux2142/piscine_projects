# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 13:10:49 by lguiller          #+#    #+#              #
#    Updated: 2017/12/13 11:57:58 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = ./get_next_line.c ./main.c

INC = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft all
	@clang $(FLAGS) $(SRCS) $(INC) -o $(NAME)

clean:
	@make -C libft clean

fclean:
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
