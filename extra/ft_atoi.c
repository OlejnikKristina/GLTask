
int		space(char c)
{
	return (c == ' ' || c == '\n' ||
	c == '\t' || c == '\r' || c == '\f' || c == '\v');
}

int		ft_atoi(const char *nptr)
{
	int			res_i;
	short int	sign;

	sign = 1;
	res_i = 0;
	while (space(*nptr))
		nptr++;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		sign = -1;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res_i = res_i * 10 + *nptr - '0';
		nptr++;
	}
	return (res_i * sign);
}
