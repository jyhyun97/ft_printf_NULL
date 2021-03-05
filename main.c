#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *str;

	//str = "aaa%-5.*saaa%000*.*daaa\n";
	str = "aaa-5.*saaa000*.*daaa\n";
	ft_printf(str, 2, "!@#$", 3, 4, 9999);
	printf("return value\t: %d\n", g_flag.count);
	return (0);
}
