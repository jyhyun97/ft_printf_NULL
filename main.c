#include "ft_printf.h"

int main(void)
{
  printf("%d", ft_printf("|%-5c|\n",'a')); // 8
  printf("%d", ft_printf("|%-5s|\n","Hello"));
  printf("%d", ft_printf("|%-5%|\n"));
  return(0);
}
