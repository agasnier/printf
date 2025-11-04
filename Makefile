NAME = libftprintf.a
CC = cc
CFLAGS = -Werror -Wall -Wextra

SRCS = ft_printf.c \
	ft_orchestror.c \
	ft_struct.c \
	ft_format_char.c \
	ft_format_num.c \
	ft_format_hex.c \
	ft_apply_sign.c \
	ft_apply_precision.c \
	ft_apply_hash.c \
	ft_apply_width.c 
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus




