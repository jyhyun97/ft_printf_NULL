#include "ft_printf.h"
#include <assert.h>

int main(void)
{
char *s=0;
    ft_printf("-->|%-4.5d|<--\n",-135);
    ft_printf("-->|%-4.*d|<--\n", -4,-135);
    ft_printf("-->|%-4.*d|<--\n", -3,-135);
    printf("-->|%-4.5d|<--\n",-135);
    printf("-->|%-4.*d|<--\n", -4,-135);
    printf("-->|%-4.*d|<--\n", -3,-135);
    //ft_printf("-->|%8s|<--\n", s);
return 0;
}
