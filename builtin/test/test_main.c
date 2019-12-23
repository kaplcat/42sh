#include <stdio.h>
#include <builtin.h>

#define TRUE 1
#define FALSE 0

// протестить при HOME != NULL 
// при HOME == NULL 
// 

int home_test(void){

	char *want;
	char *got;
	// test cd ~
	// want = "/home/orgrave" if HOME=/home/oargrave
	
	want = NULL;
	want = getenv("HOME");
	if (want == NULL)
	{
		__uid_t	id_user;
		struct passwd	*user_info;

		id_user = geteuid();
		user_info = getpwuid(id_user);
		want = user_info->pw_dir;
		if (want == NULL)
		{
			fprintf(stderr, "Test not verify func ft_home");
			return FALSE;
		}
		search_home_dir();
		got = "home/orgrave";
		if (strcmp(got, want) == 0)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else 
		ft_home();
	got = "/home/oargrave";
	
	if (strcmp(got, want) == 0)
	{
		return TRUE;
	} else{
		return FALSE;
	}

}



int test_cd_minus()
{
	
}


int main (int argc, char **argv)
{

	ft_cd(3, "cd -L ../");
	if (home_test == 0)
	{
		printf("Test 'home_test' FAIL\n");
		return (0); 
	}
	else 
	{
		printf ("Test home_test SUCSES\n");
	}
	return(0);
}