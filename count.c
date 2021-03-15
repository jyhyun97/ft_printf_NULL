#include "ft_printf.h"


int count_dtype(int a)
{
  char *abs;
  int abs_len;
  int cnt;
  int i;
  int z;

  abs = ft_itoa_base((unsigned int)ft_abs(a), 10, "0123456789");
  abs_len = ft_strlen(abs);
  cnt = abs_len;
  if (a < 0)
    cnt++;
  z = g_flag.width - cnt;
  while (g_flag.precision > abs_len++)
    cnt++;
  i = 0;
  //z = g_flag.width - abs_len;//g_flag.width - abs_len
  //if (a < 0)
  //  z -= 1;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
    cnt++;
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(abs);
  return (cnt);
}



int count_uxtype(unsigned int a, int base_num, char *base)
{
  char *rst;
  int len;
  int cnt;
  int i;
  int z;

  rst = ft_itoa_base(a, base_num, base);
  len = ft_strlen(rst);
  cnt = len;
  while (g_flag.precision > len++)
    cnt++;
  i = 0;
  z = g_flag.width - cnt;
  while (g_flag.minus == 0 && g_flag.zero == 1 && g_flag.precision < 0 && i++ < z)
    cnt++;
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(rst);
  return (cnt);
}


int count_ptype(long long a, char *base)
{
  char *rst;
  int len;
  int cnt;

  rst = ft_itoa_long(a, base);
  len = ft_strlen(rst);
  cnt = 2;
  cnt += len;
  if(g_flag.precision == 0 && a == 0)
    cnt--;
  free(rst);
  return (cnt);
}
