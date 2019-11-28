#include <ft_string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*d;
	size_t	len;

	d = dest + ft_strlen(dest);
	len = ft_strnlen(src, n);
	d[len] = 0;
	ft_memcpy(d, src, len);
	return (dest);
}
