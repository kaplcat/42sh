#include <ft_string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	n = ft_strnlen(s2, n);
	while (*s1)
	{
		if (!ft_memcmp(s1++, s2, n))
		{
			return ((char *)s1 - 1);
		}
	}
	return (NULL);
}
