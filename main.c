#include "ft_printf.h"

int main(void)
{
  printf("-->|%*.*d|<--\n", -1, 0, 0);
  printf("\n%d\n", ft_printf("%*.*d\n", -1, 0, 0));
  return(0);
}

/* 
 280 -Printf("-->|%*.*d|<--\n", -1, 0, d);   ==> -->| |<--
 281 +Printf("-->|%*.*d|<--\n", -1, 0, d);   ==> -->|0|<--
 	 -Printf("-->|%-4.0d|<--\n", d); ==> -->|    |<--
	 +Printf("-->|%-4.0d|<--\n", d); ==> -->|0   |<--
1243 -Printf("-->|%04.*d|<--\n", -4, d); ==> -->|0198|<--
1244 -Printf("-->|%04.*d|<--\n", -3, d); ==> -->|0198|<--
1245 -Printf("-->|%04.*d|<--\n", -2, d); ==> -->|0198|<--
1246 -Printf("-->|%04.*d|<--\n", -1, d); ==> -->|0198|<--
1247 +Printf("-->|%04.*d|<--\n", -4, d); ==> -->| 198|<--
1248 +Printf("-->|%04.*d|<--\n", -3, d); ==> -->| 198|<--
1249 +Printf("-->|%04.*d|<--\n", -2, d); ==> -->| 198|<--
1250 +Printf("-->|%04.*d|<--\n", -1, d); ==> -->| 198|<--





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