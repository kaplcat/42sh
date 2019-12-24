int	ft_atoi(const char *s)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*s && *s <=' ')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		num *= 10;
		num += (*s++ - '0');
	}
	return (num * sign);
}
