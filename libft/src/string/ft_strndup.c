#include <ft_string.h>
#include <stdlib.h>

char    *ft_strndup(const char *s, size_t n)
{
    char    *s1;

    n = ft_strnlen(s, n);
    s1 = (char *)malloc(n);
    if (s1 == NULL)
    {
        return (NULL);
    }
    s1[n] = 0;
    return (ft_memcpy(s1, s, n));
}