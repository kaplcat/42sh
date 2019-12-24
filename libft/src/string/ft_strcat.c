#include <ft_string.h>

char	*ft_strcat(char *dst, const char *src)
{
	return (ft_strcpy(dst + ft_strlen(dst), src));
}
