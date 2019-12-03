#include <ft_string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strnlen(src, n);
	if (len != n)
	{
		ft_memset(dest + len, 0, n - len);
	}
	return (ft_memcpy(dest, src, len));
}
