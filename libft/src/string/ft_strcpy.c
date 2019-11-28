#include <ft_string.h>

char	*ft_strcpy(char *dest, const char *src)
{
	return (ft_memcpy(dest, src, ft_strlen(src) + 1));
}
