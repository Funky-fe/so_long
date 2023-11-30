# Compiled Files
NAME    =    so_long
MLX        =    minilibx-linux/libmlx_Linux.a

# Compiler and flags
CC        =    cc
CFLAGS    =    -Wall -Werror -Wextra

# Files
SRCS    =	./game/controls.c		\
			./game/errors.c			\
			./game/game_errors.c	\
			./game/graphics.c		\
			./game/map.c			\
			./game/so_long.c		\
			./game/utils.c			\
			./GNL/get_next_line.c	\
			./printf/ft_printf.c	\
			./printf/functions.c	\

OBJ = $(SRCS:.c=.o)
# Colors (or Colours?)

DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m


all:        mlx $(NAME)
$(NAME): $(OBJ)
		@echo "\033[31;1mCompiling for Linux...\033[0m"
		@chmod 777 minilibx-linux/configure
		@ $(MAKE) -C minilibx-linux all
		$(CC) $(CFLAGS) -g -o $(NAME) $(OBJ) $(MLX) -lXext -lX11
		@echo "\033[32m[ ./so_long created ]"

mlx:
		@echo "$(YELLOW)Compiling MLX..."
		@$(MAKE) -C minilibx-linux all

clean:
		@echo "$(YELLOW)Cleaning...$(DEFAULT)"
		@$(MAKE) -C minilibx-linux clean
		rm -f $(OBJ)
		@echo "$(CYAN)Object Files Cleaned!$(DEFAULT)"

fclean:        clean
		@rm -f $(NAME)
		@echo "$(BLUE)Executables Cleaned!$(DEFAULT)"

re:            fclean all

.PHONY:        all bonus test clean fclean re

.SILENT: