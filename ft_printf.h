#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int				g_count;
typedef struct	_flag {
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		value;
	int		v_len;
	int		p_len;
	int		sign;
	char	type;
	char	*pvalue;
}				Flag;

void	print_per(va_list *ap, char *res, char type);
void	print_c(va_list *ap, char *res, char type);
void	print_s(va_list *ap, char *res, char type);
void	print_d(va_list *ap, char *res, char type);
void	print_p(va_list *ap, char *res, char type);
void	print_x(va_list *ap, char *res, char type);
void	print_u(va_list *ap, char *res, char type);

void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(long long n);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *d, void const *s, size_t n);
size_t	ft_strlen(const char *src);
char	*ft_itoa_base(long long value, int base, int is_upper);

void	make_flag(Flag **flag);
void	delete_flag(Flag **flag);
void	set_flag(Flag *flag, va_list *ap, char *res, char type);

void	put_str(char *a);
void	print_value(Flag *flag);
void	print_width(Flag *flag);
void    print_in_order(Flag *flag, void (*a)(Flag *),void (*b)(Flag *), void (*c)(Flag *));

void	set_res(va_list *ap, char *res);
char	*set_dtarg(char *a, int *k);
int		checker(va_list *ap, const char *a);
void	print_rst(va_list *ap, const char *format);
int		ft_printf(const char *format, ...);
#endif