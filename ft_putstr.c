#include "push_swap.h"
int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		len += ft_putchar(*str);
		str ++;
	}
	return (len);
}
