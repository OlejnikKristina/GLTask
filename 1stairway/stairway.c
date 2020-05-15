
#include "../include.h"

static int	count_stairs(const int n_stairs, const int k_stairs)
{
	int steps;

	if (k_stairs == 0)
	{
		ft_putnbr(n_stairs);
		write(1, "\n", 1);
		return (n_stairs);
	}
	else if (n_stairs <= 0 || k_stairs < 0)
		return (0);
	steps = n_stairs / k_stairs;
	if (n_stairs % k_stairs)
		steps++;
	ft_putnbr(steps);
	write(1, "\n", 1);
	return (steps);
}

int		main(int argc, char *argv[])
{
	if (argc <= 2)
		return (0);
	count_stairs(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
