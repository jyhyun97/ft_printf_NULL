#include "ft_printf.h"

extern t_list	g_check;

void	ft_lstadd(void)
{
	g_check.flag = 0;
	g_check.width = 0;
	g_check.psc = 0;
	g_check.len = 0;
	g_check.size = 0;
}
