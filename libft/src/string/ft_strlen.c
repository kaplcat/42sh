#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#define ALIGN (sizeof(size_t))
#define ONES ((size_t)-1/UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX/2+1))
#define HASZERO(x) ((x)-ONES & ~(x) & HIGHS)

size_t	ft_strlen(const char *s)
{
	const char		*p;
	const size_t	*word;

	p = s;
	while ((uintptr_t)p % ALIGN)
	{
		if (!*p)
		{
			return (p - s);
		}
		p++;
	}
	word = (const void *)p;
	while (!HASZERO(*word))
	{
		word++;
	}
	p = (const char *)word;
	while (*p)
	{
		p++;
	}
	return (p - s);
}
