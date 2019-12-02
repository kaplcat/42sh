#include <unistd.h>
#include <ft_string.h>

int	ft_putendl_fd(const char *s, int fd)
{
	ssize_t	ret;
	size_t	len;

	len = ft_strlen(s);
	ret = write(fd, s, len);
	if (ret == -1 || ret != (ssize_t)len)
		return (0);
	if (write(fd, "\n", 1) < 1)
		return (0);
	return ('\n');
}
