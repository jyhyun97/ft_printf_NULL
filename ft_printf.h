#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


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

void init_flag(void);
char *check_flag(char *a);
char *check_width(char *a, va_list ap);
char *check_precision(char *a, va_list ap);
void check_type(char *a);

void print_all(va_list ap);
void print_c(va_list ap);
void print_s(va_list ap);
void print_percent(void);
void print_d(va_list ap);
void make_dtype(int a);
int count_dtype(int a);
void print_u(va_list ap);
int count_utype(unsigned int a);
void make_utype(unsigned int a);
void print_x(va_list ap);
int count_xtype(unsigned int a, char *base);
void make_xtype(unsigned int a, char *base);
void print_p(va_list ap);
int count_ptype(long long a, char *base);
void make_ptype(long long a, char *base);


size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int ft_abs(int a);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_itoa(int n);
char *ft_itoa_u(unsigned int n);
char *ft_itoa_16(unsigned int n, char *base);
char *ft_itoa_x(long long n, char *base);

int ft_printf(const char *format, ...);


#endif