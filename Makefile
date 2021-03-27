CC      = gcc -g
LIB		= ar rcs
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
NAME	= libftprintf.a
INC     = ./ft_printf.h flag_util.h

MEM		= ft_itoa.c ft_atoi.c ft_itoa_base.c\
		  ft_printf.c ft_utils.c \
		  print_c.c print_s.c \
		  print_per.c print_d.c \
		  print_u.c print_x.c \
		  print_p.c \
		  print_common.c flag_common.c \
		  flag_common_util.c

OBJ_MEM	= $(MEM:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I$(INC)

$(NAME) : $(OBJ_MEM)
	$(LIB) $@ $^

all : $(NAME)

clean :
	$(RM) $(OBJ_MEM) $(OBJ_LST)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re