#include <stddef.h>
#include <stdint.h>
#include <limits.h>

#define ALIGN (sizeof(size_t))
#define ONES ((size_t)-1/UCHAR_MAX)
#define HIGHS (ONES * (UCHAR_MAX/2+1))
#define HASZERO(x) ((x)-ONES & ~(x) & HIGHS)

size_t	ft_strnlen(const char *s, size_t n)
{
	const char		*p;
	const size_t	*word;

	p = s;
	while ((uintptr_t)p % ALIGN)
	{
		if (!*p || !n--)
        {
			return (p - s);
        }
		p++;
	}
	word = (const void *)p;
	while (!HASZERO(*word) && n >= ALIGN)
	{
        n -= ALIGN;
		word++;
	}
	p = (const char *)word;
	while (*p && n--)
	{
		p++;
    }
	return (p - s);
}


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    printf("%zu\n", ft_strnlen(argv[1], atoi(argv[2])));
    printf("%zu\n",    strnlen(argv[1], atoi(argv[2])));
}