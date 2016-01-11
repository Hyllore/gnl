# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboucher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 14:31:39 by aboucher          #+#    #+#              #
#    Updated: 2016/01/11 17:46:25 by droly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

SRC = get_next_line.c

OBJ = $(SRC:.c=.o)

HEAD = get_next_line.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) makelibft
	@clang $(FLAGS) -c $(SRC) -I$(HEAD)
	@clang $(OBJ) libft/libft.a -o $(NAME)
	@echo "Compilation success."

makelibft:
	@make -C libft/
	@echo "Library included."

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Target cleaned."

re: fclean all

.PHONY: all makelibft clean fclean re
