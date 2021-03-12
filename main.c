#include "ft_printf.h"
#include <assert.h>

int main(void)
{
char *s="abc";
int a = 20;
while (a--)
{
    //printf("%d\t",a);
    ft_printf("-->|%-*s|<--\n", 4, s);
}
printf("-->|%-*s|<--\n", 4, s);
a = 10;
while (a--)
{
    //printf("%d\t",a);
    ft_printf("-->|%-*s|<--\n", 4, s);
}
return 0;
}