#include <ft_ctype.h>

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return ('A' - 'a' + c);
	return (c);
}
