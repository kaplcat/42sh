#include <unistd.h>
#include <ft_string.h>

int	ft_putstr(const char *s)
{
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}
