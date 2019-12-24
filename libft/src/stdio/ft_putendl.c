#include <unistd.h>
#include <ft_string.h>

int	ft_putendl(const char *s)
{
	ssize_t	ret;
	size_t	len;

	len = ft_strlen(s);
	ret = write(STDOUT_FILENO, s, len);
	if (ret == -1 || ret != (ssize_t)len)
		return (0);
	if (write(STDOUT_FILENO, "\n", 1) < 1)
		return (0);
	return ('\n');
}
