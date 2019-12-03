#include <ft_string.h>

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	ret;

	ret = 0;
	while (*s1)
	{
		if (ft_strchr(s1, *s2))
		{
			return (ret);
		}
		s1++;
		ret++;
	}
	return (ret);
}
