#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
