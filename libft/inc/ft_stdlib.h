#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

char    *ft_getenv(const char   *name);
char    *findenv__(const char *name, int *offset);
// char    *ft_putenv(const char *s); // ????


/*
 *  dont use this functions 
*/
char    *create_envrec(const char *name, const char *value);
char    **create_newenv(char **old_env, size_t append);
int     update_env(char **env, int offset, const char *name, const char *value);
int     addrec_env(char **env, const char *name, const char *value);

int     ft_setenv(const char *name, const char *value, int overwrite);
// int     ft_unsetenv(const char  *name);

#endif