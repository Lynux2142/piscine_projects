# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lguiller <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 13:10:49 by lguiller          #+#    #+#              #
#    Updated: 2017/12/12 14:48:04 by lguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRCS = ./get_next_line.c ./main.c

INC = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean

all: $(NAME)

$(NAME): $(SRCS)
	@echo "[OK]	all done."
	@make -C libft all
	@clang $(FLAGS) $(SRCS) $(INC) -o $(NAME)

clean:
	@echo "[OK]	clean done."
	@make -C libft clean

fclean:
	@echo "[OK]	fclean done."
	@make -C libft fclean
	@/bin/rm $(NAME)

re: fclean all
