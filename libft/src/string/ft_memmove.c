#include <stdint.h>
#include <ft_string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*lastd;
	const char	*lasts;

	if (dst < src)
	{
    	ft_memcpy(dst, src, n);
	}
	else
    {
		lastd = dst + (n - 1);
		lasts = src + (n - 1);
		while (n--)
		{
			*lastd-- = *lasts--;
		}
    }
	return (dst);
}
