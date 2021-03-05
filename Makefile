# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jawpark <jawpark@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/01 20:00:18 by jawpark           #+#    #+#              #
#    Updated: 2021/03/01 20:18:40 by jawpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_printf_flag.c ft_printf_format.c ft_printf_utils.c\
			ft_printf_diu.c ft_printf_diu_utils1.c ft_printf_diu_utils2.c\
			ft_printf_xp.c ft_printf_xp_utils.c ft_printf_string.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libftprintf.a

CC	=	gcc

RM	=	rm -rf

HEAD	=	ft_printf.h

CFLAGS	=	-Wall -Wextra -Werror

.c.o:	$(CC) $(CFLAGS) -I($HEAD) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re
