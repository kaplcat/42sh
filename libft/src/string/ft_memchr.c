#include <ft_string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = s;
	while (n--)
	{
		if (*p != (unsigned char)c)
		{
			p++;
			continue ;
		}
		return ((void *)p);
	}
	return (NULL);
}
