#include <ft_ctype.h>

int	ft_isgraph(int c)
{
	return (ft_isprint(c) && c != ' ');
}
