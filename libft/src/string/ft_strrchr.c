#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			ret = s;
		}
		s++;
	}
	return (ret);
}
