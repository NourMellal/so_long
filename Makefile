# Define the compiler
CC = gcc

# Define any compile-time flags
CFLAGS = -Wall -Wextra -Werror

# Define the directory containing the libft library
LIBFT_DIR = libft

# Define the name of the executable
NAME = so_long

# Define a list of source files
SRCS = main.c \
		get_next_line.c \
		get_next_line_utils.c \
		parsing.c \
		so_long_utils.c \
		check_error.c

# Define objects for all source files
OBJS = $(SRCS:.c=.o)

# Define the target that compiles our executable
all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

# Define the rule for cleaning all compiled objects
clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

# Define the rule for removing the compiled objects and the executable
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

# Define the rule for recompiling everything
re: fclean all

# Tell make that these are not actually files, but targets
.PHONY: all clean fclean re
