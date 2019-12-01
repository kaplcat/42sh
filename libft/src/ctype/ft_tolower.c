#include <ft_ctype.h>

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return ('a' - 'A' + c);
	return (c);
}
