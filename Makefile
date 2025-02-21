# Executable names
SERVER = server
CLIENT = client
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# Directories
FT_PRINTF_DIR = ./ft_printf

# Compiler settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
SRCS_SERVER_BONUS = server_bonus.c
SRCS_CLIENT_BONUS = client_bonus.c
SRCS_PRINTF = $(wildcard $(FT_PRINTF_DIR)/*.c)

# Object files
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)

# Build all
all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): $(SRCS_SERVER) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_SERVER) $(OBJS_PRINTF) -o $(SERVER)

$(CLIENT): $(SRCS_CLIENT) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_CLIENT) $(OBJS_PRINTF) -o $(CLIENT)

$(SERVER_BONUS): $(SRCS_SERVER_BONUS) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_SERVER_BONUS) $(OBJS_PRINTF) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(SRCS_CLIENT_BONUS) $(OBJS_PRINTF)
	$(CC) $(CFLAGS) $(SRCS_CLIENT_BONUS) $(OBJS_PRINTF) -o $(CLIENT_BONUS)

# Compile ft_printf object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS_PRINTF)

# Clean up all binaries and objects
fclean: clean
	rm -f $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

# Recompile everything
re: fclean all

.PHONY: all clean fclean re