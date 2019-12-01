#include <ft_string.h>
#include <ft_stdlib.h>

char    *findenv__(const char *name, int *offset)
{
    extern char **environ;
    char        **env;
    char        *eq;
    int         off;
    size_t      len;

    env = environ;
    if (name == NULL || (eq = ft_strchr(name, '=')) != NULL || 
        env == NULL || env[0] == NULL)
    {
        return (NULL);
    }
    len = ft_strlen(name);
    off = 0;
    while (env[off])
    {
        if (ft_strncmp(name, env[off], len) == 0 && env[off][len] == '=')
        {
            *offset = off;
            return (env[off] + len + 1);
        }
        off++;
    }
    return (NULL);
}

char    *ft_getenv(const char *name)
{
    int offset;

    return (findenv__(name, &offset));    
}
