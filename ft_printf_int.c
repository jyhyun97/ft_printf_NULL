#include "ft_printf_main.h"

extern t_flag  g_flag;
extern t_size  g_size;
// 8진수, 10진수 16진수 구분
static int	div_input(char c)
{
	int		div;

	div = 10;
	if (c == 'x' || c == 'X')
		div = 16;
	else if (c == 'o')
		div = 8;
	return (div);
}
//포맷에 따른 출력 구분
static char	*letter_input(char c)
{
	if (c == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789abcdef");
}
//숫자 길이
static int	type_int_len(int value, char c, int div)
{
	int		len;

	len = 0;
	if (c == 'c')
		return (1);
	if (value <= 0)
		len = 1;
	while (1)
	{
		value = value / div;
		++len;
		if (value == 0)
			break ;
	}
	return (len);
}
// 숫자를 문자로 바꿔 문자넣기 itoa
static char *ptr_input(int div, int len, int value, char c)
{
	char	*letter;
	char	*ptr;

	ptr = ft_calloc(len);
	letter = letter_input(c);
	while (--len > -1 && c != 'c')
	{
		if (value < 0)
		{
			ptr[0] = '-';
			ptr[len] = letter[-(value % div)];
			value = -(value / div);
		}
		else
		{
			ptr[len] = letter[value % div];
			value = (value / div);
			if (value == 0)
				break ;
		}
	}
	return (ptr);
}
//숫자를 문자열로 변환 시키기위한 전반적인 함수
void		change_int(int value, char c)
{
	int		len;
	int		div;
	char	*ptr;

	div = div_input(c);
	len = type_int_len(value, c, div);
	ptr = ptr_input(div, len, value, c);
	if (c == 'c')
		ptr[0] = (char)value;
	ft_putchr(ptr, len);
	ft_free(ptr);
}
