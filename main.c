#include "ft_printf.h"

int main(void)
{
	printf("%d",ft_printf("%-10c\n",'a') - 1);
	return (0);
}