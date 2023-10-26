# Compiled Files
NAME    =    so_long
MLX        =    minilibx-linux/libmlx_Linux.a

# Compiler and flags
CC        =    cc
CFLAGS    =    -Wall -Werror -Wextra

# Files
SRCS    =	./game/*.c		\
			./GNL/*.c		\
			./printf/*.c

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
$(NAME):
		@echo "\033[31;1mCompiling for Linux...\033[0m"
		@chmod 777 minilibx-linux/configure
		@ $(MAKE) -C minilibx-linux all
		$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS) $(MLX) -lXext -lX11
		@echo "\033[32m[ ./so_long created ]"

mlx:
		@echo "$(YELLOW)Compiling MLX..."
		@$(MAKE) -C minilibx-linux all

clean:
		@echo "$(YELLOW)Cleaning...$(DEFAULT)"
		@$(MAKE) -C minilibx-linux clean
		@echo "$(CYAN)Object Files Cleaned!$(DEFAULT)"

fclean:        clean
		@rm -f $(NAME) $(BONUS_NAME)
		@echo "$(BLUE)Executables Cleaned!$(DEFAULT)"

re:            fclean all

.PHONY:        all bonus test clean fclean re