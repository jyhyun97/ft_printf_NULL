#include "ft_printf.h"

int main(void)
{

  ft_printf("|%5.d|\n", 0);
  ft_printf("|%5.0d|\n", 0);
  ft_printf("|%5.0d|\n", 1);
  printf("\n"); 
  printf("|%5.d|\n", 0);
  printf("|%5.0d|\n", 0);
  printf("|%5.0d|\n", 1);
  return(0);
}

/* 
  68 -Printf("-->|%0*.*d|<--\n", 4, -4, d);  ==> -->|-001|<--
  69 -Printf("-->|%0*.*d|<--\n", 4, -3, d);  ==> -->|-001|<--
  70 -Printf("-->|%0*.*d|<--\n", 4, -2, d);  ==> -->|-001|<--
  71 -Printf("-->|%0*.*d|<--\n", 4, -1, d);  ==> -->|-001|<--
  
  72 +Printf("-->|%0*.*d|<--\n", 4, -4, d);  ==> -->|  -1|<--
  73 +Printf("-->|%0*.*d|<--\n", 4, -3, d);  ==> -->|  -1|<--
  74 +Printf("-->|%0*.*d|<--\n", 4, -2, d);  ==> -->|  -1|<--
  75 +Printf("-->|%0*.*d|<--\n", 4, -1, d);  ==> -->|  -1|<--


출력값이 커지는 예외
printf("%-9.7d", -12345)
		result : |-0012345 |
		return : 9
printf("%-7.9d", -12345)
		result : |-000012345|
		return : 10
*/
/* precision 0 출력 예외
printf("%09.7d", 12345)
		result : | 0012345|
		return : 9
printf("%07.9d", 12345)
		result : |000012345|
		return : 9
printf("%.d", 0)
		result : ||
		return : 0
printf("%.3d", 0)
		result : |000|
		return : 3
printf("% d", 12345)
		result : | 12345|
		return : 6
printf("% d", -12345)
		result : |-12345|
		return : 6
printf("% -d", 12345)
		result : | 12345|
*/