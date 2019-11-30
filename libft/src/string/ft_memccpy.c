#include <ft_string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
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
