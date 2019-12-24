#include <ft_string.h>

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*d;
	size_t	len;

	d = dst + ft_strlen(dst);
	len = ft_strnlen(src, n);
	d[len] = 0;
	ft_memcpy(d, src, len);
	return (dst);
}
