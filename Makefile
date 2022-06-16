# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jervasti <jonne.ervasti@student.hive.fi>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 09:18:51 by jervasti          #+#    #+#              #
#    Updated: 2022/02/15 13:53:08 by jervasti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c list.c checker.c mapfunctions.c solve.c

TSTDIR = ./eval_tests/

FLAGS = -Wall -Wextra -Werror

LIB = -L libft -lft

all: $(NAME)

$(NAME):
	@make -C libft
	gcc $(FLAGS) $(SRC) ./libft/libft.a -o $(NAME)

f:
	gcc $(FLAGS) -g -fsanitize=address $(SRC) -o $(NAME) -I libft $(LIB)

test:
	@make -C eval_tests

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
