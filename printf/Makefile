# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 14:37:58 by rlima-fe          #+#    #+#              #
#    Updated: 2023/10/16 18:31:16 by rlima-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libftprintf.a

SRC = ft_printf functions
OBJ_DIR = Obj

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

RM = rm -f

# Colors

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all:$(NAME)

$(NAME): $(SRC:=.o)
		@ar rcs $(NAME) $(SRC:=.o)
		@echo "$(GREEN)ft_printf compiled!$(DEFAULT)"


bonus: fclean all

clean:
		$(RM) $(SRC:=.o)
		@echo "$(BLUE)ft_printf object files cleaned!$(DEFAULT)"

fclean: clean
		$(RM) $(NAME)
		@echo "$(RED)libftprintf.a deleted!$(DEFAULT)"

re: 	fclean $(NAME)
		@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEFAULT)"

.PHONY:		all clean fclean re