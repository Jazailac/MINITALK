CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c \
	 ft_putchar.c \
	 ft_putnbr.c \
	 ft_putstr.c \
	 ft_putnbr_base.c \
	ft_atoi.c \

OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
