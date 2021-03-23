CC      = cc -g
LIB		= ar rcs
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
NAME	= libftprintf.a
INC     = ./ft_printf.h

MEM		= ft_itoa.c ft_atoi.c ft_itoa_base.c\
		  ft_printf_main.c ft_utils.c \


# LST		= ft_lstmap.c ft_lstnew.c \
# 		  ft_lstiter.c ft_lstlast.c \
# 		  ft_lstclear.c ft_lstsize.c \
# 		  ft_lstdelone.c ft_lstadd_back.c \
# 		  ft_lstadd_front.c

OBJ_MEM	= $(MEM:.c=.o)
# OBJ_LST	= $(LST:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I$(INC)

$(NAME) : $(OBJ_MEM)
	$(LIB) $@ $^

all : $(NAME)

# bonus : $(OBJ_LST)
# 	$(LIB) $(NAME) $^

clean :
	$(RM) $(OBJ_MEM) $(OBJ_LST)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re