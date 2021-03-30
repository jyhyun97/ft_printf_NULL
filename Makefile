# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jumoon <jumoon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 20:40:04 by jumoon            #+#    #+#              #
#    Updated: 2021/03/30 20:48:27 by jumoon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

COPTION=-c -o

AR=ar rcs

RM=rm -f

SRC=ft_printf.c parse.c print_cspx.c print_diu.c utils1.c utils2.c

OBJ=$(SRC:.c=.o)

.c.o: 
	$(CC) $(CFLAGS) $(COPTION) $@ $<

$(NAME): $(OBJ)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: libft all clean fclean re
