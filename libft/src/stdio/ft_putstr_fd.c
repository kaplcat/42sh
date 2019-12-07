#include <unistd.h>
#include <ft_string.h>

int	ft_putstr_fd(const char *s, int fd)
{
	return (write(fd, s, ft_strlen(s)));
}
