#include <ft_ctype.h>

int	ft_ispunct(int c)
{
	return (ft_isprint(c) && !ft_isspace(c) && !ft_isalnum(c));
}
