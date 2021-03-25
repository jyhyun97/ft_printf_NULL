
NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

COPTION=-c -o

AR=ar rcs

RM=rm -f

SRC=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c \

SRC_LIBFT=ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

OBJ=$(SRC:.c=.o)

OBJ_LIBFT=$(SRC_LIBFT:.c=.o)

.c.o: 
	$(CC) $(CFLAGS) $(COPTION) $@ $<

$(NAME): $(OBJ)
	$(AR) $@ $^

libft: $(OBJ_LIBFT)
	$(AR) $(NAME) $^

all: $(NAME) libft

clean:
	$(RM) $(OBJ) $(OBJ_LIBFT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: libft all clean fclean re
