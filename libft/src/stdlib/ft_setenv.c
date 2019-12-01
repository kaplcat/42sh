#include <ft_stdlib.h>
#include <ft_string.h>
#include <stdlib.h>

static char	**g_orig_env;
static char	**g_new_env;

/*
 *	Copy environ to new heap memory
 *
 *	@append -- number of records for reserve
 *	=return -- copied environ
 */
static char	**env_create_copy(size_t append)
{
	extern char	**environ;
	char		**env;
	size_t		i;
	size_t		c;

	c = 0;
	while (environ[c])
		c++;
	if ((env = malloc((c + 1 + append) * sizeof(char *))) == NULL)
		return (NULL);
	i = 0;
	while (i < c)
	{
		env[i] = g_new_env ? environ[i] : ft_strdup(environ[i]);
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

int			ft_setenv(const char *name, const char *value, int overwrite)
{
	extern char	**environ;
	char		*find;
	char		**tmp_env;

	if ((find = ft_getenv(name)) == NULL && !overwrite)
		return (0);
	if (g_new_env == NULL || find == NULL)
	{
		if ((tmp_env = env_create_copy(!find)) == NULL)
			return (-1);
		free(g_new_env);
		if (g_new_env == NULL)
			g_orig_env = environ;
		g_new_env = tmp_env;
		environ = g_new_env;
	}
	if (find)
		return (env_update_record(g_new_env, name, value));
	return (env_append_record(g_new_env, name, value));
}

void		ft_unsetenv(const char *name)
{
	extern char	**environ;
	int			offset;

	if (environ == NULL || environ[0] == NULL)
		return ;
	if (findenv__(name, &offset) == NULL)
		return ;
	if (g_new_env)
		free(environ[offset]);
	environ[offset] = NULL;
	while (environ[offset + 1])
	{
		environ[offset] = environ[offset + 1];
		offset++;
	}
	environ[offset] = NULL;
}

__attribute__((destructor))
static void	clean_env(void)
{
	extern char	**environ;
	char		**tmp_env;

	tmp_env = g_new_env;
	if (tmp_env != NULL)
	{
		while (*tmp_env)
		{
			free(*tmp_env);
			tmp_env++;
		}
		free(g_new_env);
		g_new_env = NULL;
		environ = g_orig_env;
	}
}
