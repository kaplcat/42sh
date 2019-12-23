#include <builtin.h>
#include <string.h>

#define OLDPWD "OLDPWD"
#define PWD "PWD"


void	replacement(char *current_dir, char *following_dir)
{
	// ft_setenv(PWD, current_dir);
	// ft_setenv(OLDPWD, following_dir);
}

char	*search_home_dir(void) //static 
{
	char			*name_user; //имя текущего пользователя
	__uid_t			id_user; // id пользователя un_int
	struct passwd	*user_info; //  структура в которой хранится вся инфа о пользователе !парсится из файла  passwd
	char			*home_dir_user;// домашняя директория пользователя выдергивается из структуры user_info

	if ((name_user = getenv("USER")) != NULL)
	{
		user_info = getpwnam(name_user);
		// home_dir_user = strcpy(strdup(strlen(user_info->pw_dir)), user_info->pw_dir);
		return(home_dir_user);
	}
	else
	{
		id_user =  geteuid();
		user_info = getpwuid(id_user);
		// if (home_dir_user = strcpy(strdup(strlen(user_info->pw_dir)), user_info->pw_dir) != NULL)
		// {
		// 	return(home_dir_user);
		// }
		// else if (name_userstrcpy(strdup(strlen(user_info->pw_dir)), user_info->pw_dir) != NULL) // i have no idea why l needed it
		// {
		// 	;/* code */
		// }
		
	}
	
	return(0);
}


// int ft_home(char *path)
int	ft_home(void) // static
{
	char	*home;
	char	*following_dir;

	following_dir = getcwd(NULL, 0);
	if ((home = getenv("HOME")) != NULL)
	{
		if(chdir(home) == -1)
		{
			perror("error moving to home directory");
			return(1);
		}
		else 
			printf ("home == %s\n",home);
		// replacement(home, following_dir);
	}
	else if((home = (search_home_dir())) !=  NULL)
	{
		if (chdir(home) == -1)
		{
			perror("error moving to home directory");
			return (1);
		}
		free(home);
		// replacement(home, following_dir);
		return(0);
	}
	else 
	{
		fprintf(stderr, "HOME not set\n");
		return(1);
	}
	return (0);
}

int swap_dir(void)
{
	char *current_dir;
	char *following_dir;


	// if (ft_getenv(PWD) == NULL || ft_getenv(OLDPWD) == NULL)
	// {
	// 	return 1;
	// }
	current_dir = getcwd(NULL, 0);
	if (chdir(getenv(OLDPWD)) == -1)
	{
		free(current_dir);
		perror("21sh");
		return 1;
	}
	following_dir = getcwd(NULL, 0); // ошибка логики текущий путь == предыдущему 
	// replacement(current_dir, following_dir);
	free(current_dir);
	free(following_dir);
	return 0;

}

int		to_path(char *path)
{
	char	*current_dir;		//текущаю директория
	char	*following_dir; 	// следующая директория куда мы перешли
	current_dir = getcwd(NULL, 0);
	if(chdir(path) == -1)
	{
		free(current_dir);
		perror("21sh"); 		// посмотреть можно ли юзать
		return 1;
	}
								// ft_setenv("OLDPWD", current_dir);
	free(current_dir);
	
	following_dir = getcwd(NULL, 0);
								// setenv(PWD, following_dir);
	free(following_dir);
	return(0);

}

/* НЕ забытЬ!!!!!!!!
** posix flag -L -P
*/
int		ft_cd(int argc, char *argv)
{
	if (argc == 1)
	{
		/*
		** если 1 то переход в дом.директрорию ">> cd"
		** 											1
		*/
		return(ft_home());
	}
	else if (argc == 2)
	{
		/*
		** cd -
		**  1 2
		*/
		if(strcmp(argv, "-") == 0)
		{
			return swap_dir();
		}
		else
		{
			return to_path(argv);
		}
		
	}
	else 
	{
		fprintf(stderr, "too many arg\n");
	}
	return(1);
}