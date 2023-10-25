# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/14 12:58:00 by rlima-fe          #+#    #+#              #
#    Updated: 2023/10/25 19:01:10 by rlima-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := ./game/*.c
GETNEXTLINE := ./GNL/*c
PRINTF := ./printf/libftprintf.a
LIBRARY := -L ./libft -lft -L ./mlx -lX11 -lXext -lm -lmlx -lbsd
MINILIBX := minilibx-linux/

all:
	make -C $(MINILIBX)
	@make -C printf
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MINILIBX)
		make fclean -C printf
		rm -rf $(NAME)

re: fclean all