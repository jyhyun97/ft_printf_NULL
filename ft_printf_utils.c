#include "ft_printf_main.h"

extern t_flag  g_flag;
extern t_size  g_size;
//출력 및 최종 길이 정하기
void	ft_putchr(char *ptr, int i)
{
	write(1, ptr, i);
	g_size.all_size += i;
}
// 프리후 널값 넣어주기
void	ft_free(char *ptr)
{
	free(ptr);
	ptr = 0;
}
// 메모리 할당 및 0로 추가
char 	*ft_calloc(int len)
{
	char 	*ptr;

	if (len == 0)
		len = 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	while(--len > -1)
		ptr[len] = 0;
	return (ptr);
}
// 포맷 따른 분류 d,i,c,s 되어 있음
int		format_checker(const char *format, va_list ap)
{
	int		i;
	char	*s;
	i = 0;
	while (format[i])
	{
		if (format[i] == 'd' || format[i] == 'i')
			change_int(va_arg(ap, int), format[i]);
		else if (format[i] == 'c')
			change_int(va_arg(ap, int), format[i]);
		else if (format[i] == 's')
			change_string(va_arg(ap, char*));
		else
			break;
		i++;
	}
	return (--i);
}
//전역 구조체 초기화
void    flag_size_reset(void)
{
    // flag 초기화
    g_flag.minus = 0;
    g_flag.plus = 0;
    g_flag.shap = 0;
    g_flag.space = 0;
    g_flag.zero = 0;
	// 폭, 정밀도, 길이 초기화
    g_flag.width = 0;
    g_flag.precision = 0;
    g_flag.length = 0;
}
