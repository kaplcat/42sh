#include <ft_string.h>

void	*ft_mempcpy(void *dest, const void *src, size_t n)
{
	return (ft_memcpy(dest, src, n) + n);
}
