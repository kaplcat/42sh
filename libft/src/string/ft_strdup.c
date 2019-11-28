#include <ft_string.h>
#include <stdlib.h>

char    *ft_strdup(const char *s)
{
    char    *s1;
    size_t  n;

    n = ft_strlen(s);
    s1 = (char *)malloc(n);
    if (s1 == NULL)
    {
        return (NULL);
    }
    s1[n] = 0;
    return (ft_memcpy(s1, s, n));
}