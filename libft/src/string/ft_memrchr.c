#include <stddef.h>

void	*ft_memrchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	const void			*ret;

	ret = NULL;
	p = s;
	while (n--)
	{
		if (*p == (unsigned char)c)
		{
			ret = p;
		}
		p++;
	}
	return ((void *)ret);
}
