#include "ft_printf.h"
#include <assert.h>

int main(void)
{
char *s=0;
    ft_printf("-->|%8.16s|<--\n", s);
    ft_printf("-->|%8s|<--\n", s);
return 0;
}