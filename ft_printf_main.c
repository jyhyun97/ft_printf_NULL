#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct t_list
{
	int		flag;  // +, - 
	int		space_zero; // " ", 0
	int		width; // .0000 소수점
	int		length; //  
}				s_list;

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return ((char*)s);
	return (NULL);
}

static void  format(const char *str, char type, int len, va_list ap)
{
	printf("\n");
	puts("-------------------------------------------");
	printf("in format str: %s\n", str);
	printf("in format type: %c, len: %d\n", type, len);
	puts("-------------------------------------------");
	if (type == 'c')
		printf("call c: %c\n", va_arg(ap, int));
	else if (type == 's')
		printf("call s: %s\n", va_arg(ap, char *));
	else if (type == 'p')
		printf("call p: %p\n", va_arg(ap, void *));
	else if (type == 'd')
		printf("call d: %d\n", va_arg(ap, int));
	else if (type == 'i')
		printf("call i: %i\n", va_arg(ap, int));
	else if (type == 'u')
		printf("call u: %u\n", va_arg(ap, unsigned int));
	else if (type == 'x')
		printf("call x: %x\n", va_arg(ap, unsigned int));
	else 
		printf("call X: %X\n", va_arg(ap, unsigned int));
	puts("--------------- end of format ------------------");
}

static int checker(const char *str, va_list ap)
{
	int i;
	char *type_str = "cspdiuxX";
	char *found;

	i = 1;
	if (str[1] == '%')
	{
		write(1, &str[i], 1);
		return (i);
	}
	while (str[i])
	{
		if ((found = ft_strchr(type_str, str[i])))
		{
			format(str + 1, found[0], i, ap);
			return (i);
		}
		i++;
	}
	return (0);
}

int print_rst(va_list ap, const char *format)
{
    int i;
    int len;


    i = 0;
    len = 0;
	printf("============ in print_rst =================\n");
    while (format[i])
    {
        if (format[i] == '%')
            i += checker(&format[i], ap); //서식 지정자인지 확인
        else
            write(1, &format[i], 1);
        i++;
    }
	printf("============ end of print_rst =================\n");
	return (i);
}

int ft_printf(const char *format, ...)
{
    int rst;
    va_list ap;

	printf("============ in ft_printf =================\n");
	printf("format: %s\n", format);
    va_start(ap, format);
    rst = print_rst(ap, format);
	va_end(ap);
	printf("============ end of ft_printf =================\n");
    return (rst);
}

int main(void)
{
	char *tmp = "Hello, world!";

	ft_printf("asdfsapercentstart:%%:Here 3dstart:%3d:sadfsafsdfdsfs:12d:start:%12dstr start:%s:this is end.\n", 10, 20, tmp);
	return (0);
}
