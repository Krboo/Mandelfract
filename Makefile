# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmartine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 19:43:41 by pmartine          #+#    #+#              #
#    Updated: 2016/05/16 15:46:49 by pmartine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = src/color.c src/env.c src/event.c src/fractals.c src/draw.c \
	src/main.c src/mouse.c

FLAGS = -Wall -Werror -Wextra

$(NAME):
	@make -C libft/ re
	@make -C minilibx_macos/ re
	@gcc $(CFLAGS) -o $(NAME) $(SRC) -I libft/includes/libft.h \
	-lmlx -framework OpenGl -framework Appkit libft/libft.a
	@echo "program 'fractol' created"
all: $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@make -C minilibx_macos/ clean
	@make -C libft/ fclean
	@echo "all files removed"

re: fclean all

push: fclean
	git add *
	git commit -m "auto maj"
	git push

.PHONY : all clean fclean re
