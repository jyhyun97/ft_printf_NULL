#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_flag
{
  int   minus;
  int   zero;
  int   precision;
  int   width;
	char	type;
  int   count;
}				t_flag;

t_flag g_flag;
//check.c ok
void init_flag(void);
char *check_flag(char *a);
char *check_width(char *a, va_list ap);
char *check_precision(char *a, va_list ap);
void check_type(char *a);

void print_all(va_list ap);
void padding(int byte);
void print_c(va_list ap);
void print_s(va_list ap);
void print_percent(void);

void print_d(va_list ap);
int count_dtype(int a);
void make_dtype(int a);//줄이기

void print_u(va_list ap);
//int count_utype(unsigned int a, char *base);
//void make_utype(unsigned int a, char *base);

void print_x(va_list ap);
int count_uxtype(unsigned int a, int base_num, char *base);
void make_uxtype(unsigned int a, int base_num, char *base);//얘도 줄이기

void print_p(va_list ap);
int count_ptype(long long a, char *base);
void make_ptype(long long a, char *base);

//util.c ok
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int ft_abs(int a);

//itoa.c ok
//char *fill_itoa(int n, int digit, char *rst);
//char		*ft_itoa(int n);
//char *ft_itoa_u(unsigned int n);
char *ft_itoa_base(unsigned int n, int base_num, char *base);
char *ft_itoa_long(long long n, char *base);

//ft_printf.c ok
void checker(va_list ap, char **format);
void print_rst(va_list ap, char *format);
int ft_printf(const char *format, ...);


#endif