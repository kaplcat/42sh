#include <ft_string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (ft_strchr(s2, *s1++))
		{
			return ((char *)--s1);
		}
	}
	return (NULL);
}
