#include <ft_string.h>

size_t  ft_strlcat(char *dst, const char *src, size_t n)
{
    size_t  srclen;
    size_t  dstlen;

    srclen = ft_strlen(src);
    dstlen = ft_strnlen(dst, n);
    if (dstlen == n)
    {
        return (n + srclen);
    }
    if (srclen < n - dstlen)
    {
        ft_memcpy(dst+dstlen, src, srclen+1);
    }
    else
    {
        ft_memcpy(dst+dstlen, src, n - 1);
        dst[dstlen + n - 1] = '\0';
    }
    return (dstlen + srclen);
}
