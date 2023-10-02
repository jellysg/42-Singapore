NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_putaddress.c ft_putalnum.c ft_puthex.c ft_putstr.c
OBJS = $(SRCS:.c=.o)
LIBC = ar rcs
RM = rm -f

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	@echo "$(NAME) compiled successfully."

all: $(NAME)

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@echo "Object files cleaned."

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME) cleaned."

re: fclean all

.PHONY : all clean fclean re
