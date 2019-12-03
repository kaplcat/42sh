#include <unistd.h>
#include <ft_string.h>

int	ft_putstr(const char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}
