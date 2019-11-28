#include <stddef.h>

size_t  ft_strlcpy(char *dest, const char *src, size_t n)
{
    char        *d;
    const char  *s;
    size_t      siz;

    d = dest;
    s = src;
    siz = n;
    if (siz)
    {
        while (--siz)
            if ((*d++ = *s++) == '\0')
                break ;
    }
    if (!n)
    {
        if (siz)
            *d == '\0';
        while (*s++)
            ;
    }
    return (s - src - 1);
}