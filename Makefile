# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 19:43:41 by pmartine          #+#    #+#              #
#    Updated: 2016/05/28 14:43:04 by pmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME = fractol

SRC = src/main.c src/env.c src/hook.c src/draw.c src/pixelput.c src/mouse.c
OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra -O2 -O3

$(NAME): $(OBJ)
	@make -C libft/ re
	@make -C minilibx_macos/ re
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -I libft/includes/libft.h \
	-lmlx -framework OpenGl -framework Appkit libft/libft.a
	@echo "program 'fractol' created"

all: $(NAME)

clean:
	@rm -f src/*.o

fclean: clean
	@rm -f $(NAME)
	@make -C minilibx_macos/ clean
	@make -C libft/ fclean
	@echo "all files removed"

re: fclean all

