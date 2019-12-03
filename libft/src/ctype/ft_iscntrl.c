int	ft_iscntrl(int c)
{
	return (c == 127 || (c >= 0 && c <= 31));
}
