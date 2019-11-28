#include <ft_string.h>

size_t  ft_strlcat(char *dest, const char *src, size_t n)
{
    char        *d;
    const char  *s;
    size_t      siz;
    size_t      dlen;

    d = dest;
    s = src;
    dlen = ft_strlen(d);
    d += dlen;
    siz = n - dlen;
    if (siz == 0)
        return(dlen + ft_strlen(s));
    while (*s)
    {
        if (n != 1)
        {
            *d++ = *s;
            n--;
        }
        s++;
    }
    *d = '\0';
    return (dlen + s - src);
}