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
  //int   star;
  int	count;
}				t_flag;

t_flag g_flag;



void init_flag();
char *check_flag(char *a);
char *check_width(char *a, va_list ap);
char *check_precision(char *a, va_list ap);
void check_type(char *a);

void print_all(va_list ap);
//int print_all2(va_list ap);
int print_c(va_list ap);
int print_s(va_list ap);
int print_d(va_list ap);
int print_percent();

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int ft_printf(const char *format, ...);


#endif