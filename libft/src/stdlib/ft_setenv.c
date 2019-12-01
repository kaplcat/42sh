#include <ft_stdlib.h>
#include <ft_string.h>
#include <stdlib.h>

extern char **environ;
static char **orig_env;
static char **new_env;

/*
 *  Copy environ to new heap memory
 * 
 *  @append -- number of records for reserve
 *  =return -- copied environ
 */
char    **env_create_copy(size_t append)
{
    char        **env;
    size_t      i;
    size_t      c;

    c = 0;
    while (environ[c])
        c++;
    env = malloc((c + 1 + append) * sizeof(char *));
    if (env == NULL)
        return (NULL);
    i = 0;
    while (i < c)
    {
        env[i] = new_env ? environ[i] : ft_strdup(environ[i]);
        if (env[i] == NULL)
        {
            while (i > 0)
                free(env[i-- - 1]);
            free(env);
            return (NULL);
        }
        i++;
    }
    env[i] = NULL;
    return (env);
}

int ft_setenv(const char *name, const char *value, int overwrite)
{
    char    *find;
    char    **tmp_env;

    if ((find = ft_getenv(name)) == NULL && !overwrite)
        return (0);
    if (new_env == NULL || find == NULL)
    {
        if ((tmp_env = env_create_copy(!find)) == NULL)
            return (-1);
        free(new_env);
        if (new_env == NULL)
            orig_env = environ;
        new_env = tmp_env;
        environ = new_env;
    }
    if (find)
        return (env_update_record(new_env, name, value));
    return (env_append_record(new_env, name, value));
}

void ft_unsetenv(const char *name)
{
    int offset;;

    if (environ == NULL || environ[0] == NULL)
        return ;
    if (!findenv__(name, &offset))
        return ;
    if (new_env)
        free(environ[offset]);
    environ[offset] = NULL;
    while (environ[offset + 1])
    {
        environ[offset] = environ[offset + 1];
        offset++;
    }
}

__attribute__((destructor))
static void clean_env(void)
{
    char    **tmp_env;

    tmp_env = new_env;
    if (tmp_env != NULL)
    {
        while (*tmp_env)
        {
            free(*tmp_env);
            tmp_env++;
        }
        free(new_env);
        new_env = NULL;
        environ = orig_env;
    }
}