#include "push_swap.h"
int	ft_putnbr(long int n)
{
	long long int	nbr;
	int				len;

	nbr = n;
	len = 0;
	if (nbr == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		len = 1;
	}
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	len += ft_putchar(nbr % 10 + '0');
	return (len);
}
