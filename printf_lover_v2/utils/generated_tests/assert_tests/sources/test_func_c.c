/*
** charmstr@student.42.fr
*/

#include "../includes/printf_lover_test_func.h"
#include "../includes/ft_printf.h"
#include <stdio.h>
#include <assert.h>
#include "../includes/printf_lover_test_func.h"

int	test_func_c(int c)
{
setbuf(stdout, NULL);
assert(printf("-->|%-4.c|<--\n", c) == ft_printf("-->|%-4.c|<--\n", c));
assert(printf("-->|%-4c|<--\n", c) == ft_printf("-->|%-4c|<--\n", c));
assert(printf("-->|%-3.c|<--\n", c) == ft_printf("-->|%-3.c|<--\n", c));
assert(printf("-->|%-3c|<--\n", c) == ft_printf("-->|%-3c|<--\n", c));
assert(printf("-->|%-2.c|<--\n", c) == ft_printf("-->|%-2.c|<--\n", c));
assert(printf("-->|%-2c|<--\n", c) == ft_printf("-->|%-2c|<--\n", c));
assert(printf("-->|%-1.c|<--\n", c) == ft_printf("-->|%-1.c|<--\n", c));
assert(printf("-->|%-1c|<--\n", c) == ft_printf("-->|%-1c|<--\n", c));
assert(printf("-->|%.c|<--\n", c) == ft_printf("-->|%.c|<--\n", c));
assert(printf("-->|%c|<--\n", c) == ft_printf("-->|%c|<--\n", c));
assert(printf("-->|%*.c|<--\n", -4, c) == ft_printf("-->|%*.c|<--\n", -4, c));
assert(printf("-->|%*.c|<--\n", -3, c) == ft_printf("-->|%*.c|<--\n", -3, c));
assert(printf("-->|%*.c|<--\n", -2, c) == ft_printf("-->|%*.c|<--\n", -2, c));
assert(printf("-->|%*.c|<--\n", -1, c) == ft_printf("-->|%*.c|<--\n", -1, c));
assert(printf("-->|%*.c|<--\n", 0, c) == ft_printf("-->|%*.c|<--\n", 0, c));
assert(printf("-->|%*.c|<--\n", 1, c) == ft_printf("-->|%*.c|<--\n", 1, c));
assert(printf("-->|%*.c|<--\n", 2, c) == ft_printf("-->|%*.c|<--\n", 2, c));
assert(printf("-->|%*.c|<--\n", 3, c) == ft_printf("-->|%*.c|<--\n", 3, c));
assert(printf("-->|%*.c|<--\n", 4, c) == ft_printf("-->|%*.c|<--\n", 4, c));
assert(printf("-->|%*c|<--\n", -4, c) == ft_printf("-->|%*c|<--\n", -4, c));
assert(printf("-->|%*c|<--\n", -3, c) == ft_printf("-->|%*c|<--\n", -3, c));
assert(printf("-->|%*c|<--\n", -2, c) == ft_printf("-->|%*c|<--\n", -2, c));
assert(printf("-->|%*c|<--\n", -1, c) == ft_printf("-->|%*c|<--\n", -1, c));
assert(printf("-->|%*c|<--\n", 0, c) == ft_printf("-->|%*c|<--\n", 0, c));
assert(printf("-->|%*c|<--\n", 1, c) == ft_printf("-->|%*c|<--\n", 1, c));
assert(printf("-->|%*c|<--\n", 2, c) == ft_printf("-->|%*c|<--\n", 2, c));
assert(printf("-->|%*c|<--\n", 3, c) == ft_printf("-->|%*c|<--\n", 3, c));
assert(printf("-->|%*c|<--\n", 4, c) == ft_printf("-->|%*c|<--\n", 4, c));
assert(printf("-->|%1.c|<--\n", c) == ft_printf("-->|%1.c|<--\n", c));
assert(printf("-->|%1c|<--\n", c) == ft_printf("-->|%1c|<--\n", c));
assert(printf("-->|%2.c|<--\n", c) == ft_printf("-->|%2.c|<--\n", c));
assert(printf("-->|%2c|<--\n", c) == ft_printf("-->|%2c|<--\n", c));
assert(printf("-->|%3.c|<--\n", c) == ft_printf("-->|%3.c|<--\n", c));
assert(printf("-->|%3c|<--\n", c) == ft_printf("-->|%3c|<--\n", c));
assert(printf("-->|%4.c|<--\n", c) == ft_printf("-->|%4.c|<--\n", c));
assert(printf("-->|%4c|<--\n", c) == ft_printf("-->|%4c|<--\n", c));
assert(printf("-->|%--4.c|<--\n", c) == ft_printf("-->|%--4.c|<--\n", c));
assert(printf("-->|%--4c|<--\n", c) == ft_printf("-->|%--4c|<--\n", c));
assert(printf("-->|%--3.c|<--\n", c) == ft_printf("-->|%--3.c|<--\n", c));
assert(printf("-->|%--3c|<--\n", c) == ft_printf("-->|%--3c|<--\n", c));
assert(printf("-->|%--2.c|<--\n", c) == ft_printf("-->|%--2.c|<--\n", c));
assert(printf("-->|%--2c|<--\n", c) == ft_printf("-->|%--2c|<--\n", c));
assert(printf("-->|%--1.c|<--\n", c) == ft_printf("-->|%--1.c|<--\n", c));
assert(printf("-->|%--1c|<--\n", c) == ft_printf("-->|%--1c|<--\n", c));
assert(printf("-->|%-.c|<--\n", c) == ft_printf("-->|%-.c|<--\n", c));
assert(printf("-->|%-c|<--\n", c) == ft_printf("-->|%-c|<--\n", c));
assert(printf("-->|%-*.c|<--\n", -4, c) == ft_printf("-->|%-*.c|<--\n", -4, c));
assert(printf("-->|%-*.c|<--\n", -3, c) == ft_printf("-->|%-*.c|<--\n", -3, c));
assert(printf("-->|%-*.c|<--\n", -2, c) == ft_printf("-->|%-*.c|<--\n", -2, c));
assert(printf("-->|%-*.c|<--\n", -1, c) == ft_printf("-->|%-*.c|<--\n", -1, c));
assert(printf("-->|%-*.c|<--\n", 0, c) == ft_printf("-->|%-*.c|<--\n", 0, c));
assert(printf("-->|%-*.c|<--\n", 1, c) == ft_printf("-->|%-*.c|<--\n", 1, c));
assert(printf("-->|%-*.c|<--\n", 2, c) == ft_printf("-->|%-*.c|<--\n", 2, c));
assert(printf("-->|%-*.c|<--\n", 3, c) == ft_printf("-->|%-*.c|<--\n", 3, c));
assert(printf("-->|%-*.c|<--\n", 4, c) == ft_printf("-->|%-*.c|<--\n", 4, c));
assert(printf("-->|%-*c|<--\n", -4, c) == ft_printf("-->|%-*c|<--\n", -4, c));
assert(printf("-->|%-*c|<--\n", -3, c) == ft_printf("-->|%-*c|<--\n", -3, c));
assert(printf("-->|%-*c|<--\n", -2, c) == ft_printf("-->|%-*c|<--\n", -2, c));
assert(printf("-->|%-*c|<--\n", -1, c) == ft_printf("-->|%-*c|<--\n", -1, c));
assert(printf("-->|%-*c|<--\n", 0, c) == ft_printf("-->|%-*c|<--\n", 0, c));
assert(printf("-->|%-*c|<--\n", 1, c) == ft_printf("-->|%-*c|<--\n", 1, c));
assert(printf("-->|%-*c|<--\n", 2, c) == ft_printf("-->|%-*c|<--\n", 2, c));
assert(printf("-->|%-*c|<--\n", 3, c) == ft_printf("-->|%-*c|<--\n", 3, c));
assert(printf("-->|%-*c|<--\n", 4, c) == ft_printf("-->|%-*c|<--\n", 4, c));
assert(printf("-->|%-1.c|<--\n", c) == ft_printf("-->|%-1.c|<--\n", c));
assert(printf("-->|%-1c|<--\n", c) == ft_printf("-->|%-1c|<--\n", c));
assert(printf("-->|%-2.c|<--\n", c) == ft_printf("-->|%-2.c|<--\n", c));
assert(printf("-->|%-2c|<--\n", c) == ft_printf("-->|%-2c|<--\n", c));
assert(printf("-->|%-3.c|<--\n", c) == ft_printf("-->|%-3.c|<--\n", c));
assert(printf("-->|%-3c|<--\n", c) == ft_printf("-->|%-3c|<--\n", c));
assert(printf("-->|%-4.c|<--\n", c) == ft_printf("-->|%-4.c|<--\n", c));
assert(printf("-->|%-4c|<--\n", c) == ft_printf("-->|%-4c|<--\n", c));
	return(0);
}
/*
** charmstr@student.42.fr
**
** 144 different calls generated automatically according to your options
*/
