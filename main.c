#include "ft_printf.h"

int main(void)
{
  int a = 1;
  printf("%u %p\n", &a, &a);
  ft_printf("%u %p\n", &a, &a);
  return(0);
}

/*


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