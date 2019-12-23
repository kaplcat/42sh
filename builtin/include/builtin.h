#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pwd.h>
# include <sys/types.h>

int		ft_cd(int argc, char *argv);
int		ft_home(void);
char	*search_home_dir(void);

#endif
