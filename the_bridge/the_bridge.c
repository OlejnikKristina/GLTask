
#include "../include.h"

static void count_spans_len(const int spans, const int d)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (spans <= 0 || d <= 0)
		return ;
	while (i <= spans)
	{
		len += d * i;
		i++;
	}
	ft_putnbr(len);
	write(1, "\n", 1);
}

int		main(int argc, char *argv[])
{
	if (argc <= 2)
		return (0);
	count_spans_len(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}
