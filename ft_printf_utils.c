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

char	*ft_malloc_input(char *ptr, int len)
{
	if (len == 0)
		len = 1;
	ptr = (char *)malloc(sizeof(char) * len);
	if (!ptr)
		return (NULL);
	while(--len)
		ptr[len] = 0;
	return (ptr);

}

char	*ft_strlcpy(char *s1, char *s2, char *s3)
{
	int		i;
	int		j;

	i = 0;
	j = 0;

}
