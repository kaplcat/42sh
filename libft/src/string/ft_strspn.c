#include <ft_string.h>

size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t	ret;

	ret = 0;
	while (*s1 && ft_strchr(s2, *s1++))
	{
		ret++;
	}
	return (ret);
}
