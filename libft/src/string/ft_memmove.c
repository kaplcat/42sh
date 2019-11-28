#include <stddef.h>
#include <stdint.h>
#include <ft_string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*lastd;
	const char	*lasts;

	d = dest;
	s = src;
	if (d < s)
	{
    	while (n--)
		{
      		*d++ = *s++;
		}
	}
	else
    {
		lastd = d + (n - 1);
		lasts = s + (n - 1);
		while (n--)
		{
			*lastd-- = *lasts--;
		}
    }
	return (dest);
}
