#include <ft_string.h>

char	*ft_strcat(char *dest, char *src)
{
	ft_strcpy(dest + ft_strlen(dest), src);
	return (dest);
}
