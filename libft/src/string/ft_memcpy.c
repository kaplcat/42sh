#include <ft_string.h>
#include <stdint.h>

#define ALIGN (sizeof(int))

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (((uintptr_t)d % ALIGN || (uintptr_t)s % ALIGN) && n--)
	{
		*d++ = *s++;
	}
	while (n > ALIGN)
	{
		*(int*)d = *(int*)s;
		n -= ALIGN;
		d += ALIGN;
		s += ALIGN;
	}
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
