#include <ft_string.h>
#include <ft_stdlib.h>
#include <stdlib.h>

/* create new record for environ */
static char *env_create_record(const char *name, const char *value)
{
	size_t	namelen;
	char	*rec;

	namelen = ft_strcspn(name, "=");
	rec = (char *)malloc(namelen + ft_strlen(value) + 2);
	if (rec == NULL)
	{
		return (NULL);
	}
	ft_memcpy(rec, name, namelen);
	ft_memcpy(rec + namelen, "=", 1);
	ft_memcpy(rec + namelen + 1, value, ft_strlen(value) + 1);
	return (rec);
}

/*
 *  Add new record
 *  Env must have memory for record
*/
int			env_append_record(char **env, const char *name, const char *value)
{
	while (*env)
	{
		env++;
	}
	*env = env_create_record(name, value);
	if (*env == NULL)
	{
		return (-1);
	}
	env[1] = NULL;
	return (0);
}

/*
 *  Rewrite value by name in env
 *  Env in heap memory
*/
int			env_update_record(char **env, const char *name, const char *value)
{
	size_t	value_len;
	char	*eq;
	char	*new_rec;
	int		offset;

	if (findenv__(name, &offset) == NULL)
		return (-1);
	eq = ft_strchr(env[offset], '=');
	value_len = env[offset] + ft_strlen(env[offset]) - eq;
	if (eq == NULL || value_len < ft_strlen(value))
	{
		new_rec = env_create_record(name, value);
		if (new_rec == NULL)
			return (-1);
		free(env[offset]);
		env[offset] = new_rec;
		return (0);
	}
	else
	{
		ft_strcpy(eq + 1, value);
	}
	return (0);
}
