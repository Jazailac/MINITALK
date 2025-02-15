# Executable names
SERVER = server
CLIENT = client

# Directories
FT_PRINTF_DIR = ./ft_printf

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_PRINTF = $(wildcard $(FT_PRINTF_DIR)/*.c)

# Object files
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

# Build all
all: $(SERVER) $(CLIENT)

$(SERVER): $(SRCS_SERVER) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_SERVER) $(OBJS_PRINTF) -o $(SERVER)

$(CLIENT): $(SRCS_CLIENT) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) $(OBJS_PRINTF) -o $(CLIENT)

# Compile ft_printf object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS_PRINTF)

# Clean up all binaries and objects
fclean: clean
	rm -f $(SERVER) $(CLIENT)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re