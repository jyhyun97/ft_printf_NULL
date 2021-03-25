#include "ft_printf.h"
/*
int main(void)
{
  int a;
	//printf("\n원본 \naaa%-5.*saaa%0-*.*daaa\n", 2, "!@#$", 3, 4, 9999);
	a = ft_printf("|%-4.c|\n",'a');
	a = ft_printf("|%*.c|\n",-4, 'a');
  printf("%d\n",g_flag.width);
  printf("cnt : %d\n",a);
	a = ft_printf("%-10c\n",'a');
  printf("cnt : %d\n",a);
  ft_printf("1234567890\n");
	return (0);
}
*/
// inttest_func_c(int c)

int main(void) 
{
	char c = 'a';

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
