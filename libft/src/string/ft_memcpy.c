#include <ft_string.h>
#include <stdint.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
