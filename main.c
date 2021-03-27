#include "ft_printf.h"
#include <assert.h>

int main(void)
{
int s = 123;
ft_printf("--|%-4.2x|--\n", -30);
printf("--|%-4.2x|--\n", -30);
return 0;
}
