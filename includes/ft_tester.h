#ifndef FT_TESTER_H
# define FT_TESTER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <getopt.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>

# define HELP_MSG "Usage:\n\t./42pool_tester [options] project_directory\n\
Options:\n\t-n: skip norminette\n\t-o: write output to a file"

/*
*	workdir:			the path to the tested project.
*	folder:				the folder of tested project.
*	output:				the output (default: STDOUT) can be define to a file.
*	start_norminette:	by default, it start norminette (if found), but can be skipped.
*/
typedef struct s_config
{
	char	*workdir;
	DIR		*folder;
	char	*output;
	char	start_norminette : 1;
}	t_config;

/*
* Description:
*		Start debug process, this will start checking normes (if enabled),
*		read source code to recommand more units tests, compile souce code
*		and forked binary.
* Return value:
*		If any of steps success, the function return EXIT_SUCCESS (0),
*		else it will return EXIT_FAILURE (1).
*/
int		start_debug(t_config tester, char *units_tests);

/*
* Description:
*		Take two strings and merge them.
*/
char	*append_to_str(char *s1, char *s2);

#endif