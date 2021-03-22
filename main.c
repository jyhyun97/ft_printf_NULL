#include "ft_printf.h"
#include <assert.h>

int main(void)
{

    //ft_printf(" ft-->|%0*.*d|<--\n",-4,-5,-12);
    printf(" or-->|%-4.*d|<--\n",3,0);
    printf(" or-->|%-4.*d|<--\n",-4, 0);
    printf(" or-->|%-4.*d|<--\n",-3, 0);
    printf(" or-->|%-4.*d|<--\n",-2, 0);
    printf(" or-->|%-4.*d|<--\n",-1, 0);
    ft_printf(" ft-->|%-4.*d|<--\n",3,0);
    ft_printf(" ft-->|%-4.*d|<--\n",-4, 0);
    ft_printf(" ft-->|%-4.*d|<--\n",-3, 0);
    ft_printf(" ft-->|%-4.*d|<--\n",-2, 0);
    ft_printf(" ft-->|%-4.*d|<--\n",-1, 0);
    //ft_printf("-->|%*.4d|<--\n",1,-135);
    //printf("-->|%*.4d|<--\n",0,-135);
    //printf("-->|%*.4d|<--\n",1,-135);
    //ft_printf("-->|%8s|<--\n", s);
return 0;
}
