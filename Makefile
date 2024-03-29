# Define the compiler
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall -Wextra -Werror

# Define the directory containing the libft library
LIBFT_DIR = ./libft
PRINTF_DIR = ./printf	

# Define the name of the executable
NAME = so_long

# Define a list of source files
SRCS = main.c \
		get_next_line.c \
		get_next_line_utils.c \
		so_long_parsing.c \
		so_long_utils.c \
		so_long_check_error.c so_long_utils2.c so_long_game.c \
		so_long_game2.c so_long_game3.c so_long_utils3.c
# Define objects for all source files
OBJS = $(SRCS:.c=.o)



# ==> for MACOS

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lftprintf -lft -lmlx -framework OpenGL -framework AppKit

#  ==> for LINUX

# $(NAME): $(OBJS)
# 	make -C $(LIBFT_DIR)
# 	make -C $(PRINTF_DIR)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lftprintf -lft -lmlx -lXext -lX11 -lm

# Define the rule for compiling all source files
all: $(NAME)

# Define the rule for cleaning all compiled objects
clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

# Define the rule for removing the compiled objects and the executable
fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

# Define the rule for recompiling everything
re: fclean all

# Tell make that these are not actually files, but targets
.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
