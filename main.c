#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int format_checker(char *input)//make it better
{
	if (*input != '%')
		return (0);
	input++;
	if (*input != 'c' && *input != 's' && *input != 'p' && *input != 'd' &&
			*input != 'i' && *input != 'u' && *input != 'x' && *input != 'X')
		return (0);
	return (1);
}

int mini_printf(const char *input, ...)
{
	char *tmp;
	int rst;
	int i;
	int cnt;
	va_list ap;

	va_start(ap, input);

	i = 0;
	rst = 0;
	cnt = 0;

	tmp = (char *)malloc(sizeof(char) * (strlen(input) + 1));
	strcpy(tmp, input);

	while(input[i] != '\0')
	{
		cnt += format_checker(&tmp[i]);
		i++;
	}
	i = 0;

	printf("format specifier %d\n", cnt);

	while (i < cnt)
	{
		printf("variable argument %d\n", va_arg(ap, int));
		rst++;
		i++;
	}

	va_end(ap);
	free(tmp);
	tmp = 0;
	return (rst);
}
int main(void) {
	mini_printf("%d  %a   %X   %c  ", 1, 3, 6, 8);
	return 0;
}
