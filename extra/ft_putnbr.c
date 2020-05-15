
#include "../include.h"

void	ft_putnbr(int n)
{
	int		res;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	res = nbr % 10 + '0';
	if ((nbr / 10) != 0)
		ft_putnbr(nbr / 10);
	write(1, &res, 1);
}
