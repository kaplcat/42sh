#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	while (n--)
	{
		if ((*d++ = *s++) == c)
		{
			return (d);
		}
	}
	return (NULL);
}
