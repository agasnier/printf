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

libft_DIR = libft/

SRCS_libft =	$(libft_DIR)ft_isalpha.c \
	$(libft_DIR)ft_isdigit.c \
	$(libft_DIR)ft_isalnum.c \
	$(libft_DIR)ft_isascii.c \
	$(libft_DIR)ft_isprint.c \
	$(libft_DIR)ft_strlen.c \
	$(libft_DIR)ft_memset.c \
	$(libft_DIR)ft_bzero.c \
	$(libft_DIR)ft_memcpy.c \
	$(libft_DIR)ft_memmove.c \
	$(libft_DIR)ft_strlcpy.c \
	$(libft_DIR)ft_strlcat.c \
	$(libft_DIR)ft_toupper.c \
	$(libft_DIR)ft_tolower.c \
	$(libft_DIR)ft_strchr.c \
	$(libft_DIR)ft_strrchr.c \
	$(libft_DIR)ft_strncmp.c \
	$(libft_DIR)ft_memchr.c \
	$(libft_DIR)ft_memcmp.c \
	$(libft_DIR)ft_strnstr.c \
	$(libft_DIR)ft_atoi.c \
	$(libft_DIR)ft_calloc.c \
	$(libft_DIR)ft_strdup.c \
	$(libft_DIR)ft_substr.c \
	$(libft_DIR)ft_strjoin.c \
	$(libft_DIR)ft_strtrim.c \
	$(libft_DIR)ft_split.c \
	$(libft_DIR)ft_itoa.c \
	$(libft_DIR)ft_strmapi.c \
	$(libft_DIR)ft_striteri.c \
	$(libft_DIR)ft_putchar_fd.c \
	$(libft_DIR)ft_putstr_fd.c \
	$(libft_DIR)ft_putendl_fd.c \
	$(libft_DIR)ft_putnbr_fd.c \
	$(libft_DIR)ft_lstnew_bonus.c \
	$(libft_DIR)ft_lstadd_front_bonus.c \
	$(libft_DIR)ft_lstsize_bonus.c \
	$(libft_DIR)ft_lstlast_bonus.c \
	$(libft_DIR)ft_lstadd_back_bonus.c \
	$(libft_DIR)ft_lstdelone_bonus.c \
	$(libft_DIR)ft_lstclear_bonus.c \
	$(libft_DIR)ft_lstiter_bonus.c \
	$(libft_DIR)ft_lstmap_bonus.c

OBJS_libft = $(SRCS_libft:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_libft)
	ar rcs $(NAME) $(OBJS) $(OBJ_libft)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJ_libft)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

test: all 
	clear && cc -Werror -Wextra -Wall main.c ft_printf.a libft/libft.a && ./a.out




