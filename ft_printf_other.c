#include "ft_printf_main.h"

extern t_flag  g_flag;
extern t_size  g_size;
// 포인터 문자열 길이 구하기
static int		string_len(char *s)
{
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		++len;
	return (len);
}
// 포인트 문자열 출력
void	change_string(char *s)
{
	int		len;
	int 	cp_len;
	char	*ptr;

	len = string_len(s);
	cp_len = len;
	ptr = ft_calloc(len);
	while(--len > -1)
		ptr[len] = s[len];
	ft_putchr(ptr, cp_len);
	ft_free(ptr);
}
