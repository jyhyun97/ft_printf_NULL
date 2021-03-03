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
ft_printf("%s", "abc");
printf("\n-1\n");
printf("%s", "abc");
printf("\n-2\n");
ft_printf("%-.7s", "abc"); // 오류 abcac
printf("\n-3\n");
printf("%-.7s", "abc");
return(0);
}
