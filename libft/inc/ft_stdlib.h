#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

char    *ft_getenv(const char   *name);
int     ft_setenv(const char *name, const char *value, int overwrite);
void     ft_unsetenv(const char  *name);

char    *findenv__(const char *name, int *offset);
int     env_append_record(char **env, const char *name, const char *value);
int     env_update_record(char **env, const char *name, const char *value);


#endif