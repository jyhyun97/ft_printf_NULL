#include "ft_printf.h"
/*
int print_all(va_list ap)
{
  printf("\n구조체 출력 시작\n");
  printf("minus : %d\n", g_flag.minus);
  printf("zero : %d\n", g_flag.zero);
  printf("width : %d\n", g_flag.width);
  printf("pre : %d\n", g_flag.precision);
  printf("type : %c\n", g_flag.type);
  printf("구조체 출력 끝\n");
  print_all2(ap);
  printf("\n서식지정자 출력 끝\n");
}
*/
void except(void)
{
  if (g_flag.width < 0)
  {
    g_flag.minus = 1;
    g_flag.width *= -1;    
  }
}

int print_all(va_list ap)
{
  except();
  if (g_flag.type == 'c')
    print_c(ap);
  if (g_flag.type == 's')
    print_s(ap);
  if (g_flag.type == 'd')
    print_d(ap);
  return (0);
}

size_t padding(size_t byte)
{
  size_t i = 0;
  while (i < g_flag.width - byte)
  {
    write(1, " ", 1);
    g_flag.count++;
    i++;
  }
  return (i);
}

//     a 6
int print_c(va_list ap)
{
  char a = va_arg(ap, int);
  if (g_flag.minus)
  {
	  write(1, &a, 1);
    g_flag.count++;
	  padding(1);
  }
  else
  {
	  padding(1);
	  write(1, &a, 1);
    g_flag.count++;
  }
  return (0);
}


int print_s(va_list ap)
{
  char *s = va_arg(ap, char *);
	write(1, s, ft_strlen(s));
  g_flag.count += ft_strlen(s);
  return (0);
}


size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[i] != '\0')
		i++;
	while (src[j] != '\0' && j < dstsize - 1 && dstsize != 0)
	{
		dst[j] = src[j];
		j++;
	}
	if (dstsize > 0)
		dst[j] = '\0';
	return (i);
}
static int	cnt_digit(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	*fill_rst(char *rst, int n)
{
	int	i;
	int	digit;

	i = 0;
	digit = cnt_digit(n);
	if (n == 0)
		rst[i] = '0';
	else if (n < 0)
	{
		rst[i] = '-';
		n *= -1;
	}
	i++;
	while (n > 0)
	{
		rst[digit - i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	rst[digit] = '\0';
	return (rst);
}

char		*ft_itoa(int n)
{
	char	*rst;
	int		digit;

	digit = cnt_digit(n);
	if (digit == 0)
		return (0);
	rst = (char *)malloc(sizeof(char) * digit + 1);
	if (rst == 0)
		return (0);
	if (n == -2147483648)
		ft_strlcpy(rst, "-2147483648", 12);
	else
		fill_rst(rst, n);
	return (rst);
}


int print_d(va_list ap)
{
  char *s = ft_itoa(va_arg(ap, int));
	write(1, s, ft_strlen(s));
    g_flag.count += ft_strlen(s);
  return (0);
}

//할 것 : 예외사항 먼저 처리하고, 경우에 따라 출력~!

//void 예외처리();
//int 메인 출력부();//여기서 플래그 따라 이동