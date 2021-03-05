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


size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int ft_abs(int a);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int	cnt_digit(int n);
char	*fill_rst(char *rst, int n);
char		*ft_itoa(int n);

int ft_printf(const char *format, ...);


#endif