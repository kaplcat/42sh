#include <ft_string.h>
#include <ft_stdlib.h>

char	*findenv__(const char *name, int *offset)
{
	extern char	**environ;
	char		**env;
	char		*eq;
	int			i;
	size_t		len;

	env = environ;
	if (name == NULL || (eq = ft_strchr(name, '=')) != NULL ||
		env == NULL || env[0] == NULL)
	{
		return (NULL);
	}
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(name, env[i], len) == 0 && env[i][len] == '=')
		{
			*offset = i;
			return (env[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

char	*ft_getenv(const char *name)
{
	int	offset;

	return (findenv__(name, &offset));
}
