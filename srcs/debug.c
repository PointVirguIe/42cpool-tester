#include "../includes/ft_tester.h"

static int	exec_units(t_config tester)
{
	if (tester.output)
		return (EXIT_SUCCESS);
	// if (tester.start_norminette)
	// 	execute bin
	return (EXIT_SUCCESS);
}

static void	read_source(DIR *workdir, char *units_tests)
{
	struct dirent	*dent;
	struct stat		st;
	int				st_state;

	dent = readdir(workdir);
	while (dent)
	{
		if (strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0)
			continue ;
		st_state = fstatat(dirfd(workdir), dent->d_name, &st, 0);
		if (st_state > 0 && S_ISDIR(st.st_mode))
			continue ; // read dir again...
		(void) units_tests; // recommand units tests?
		dent = readdir(workdir);
	}
}

static int	clean_workdir(char *folder)
{
	int	obj;
	int	suggest_units;

	obj = remove("*.o");
	suggest_units = remove("*.42pool~");
	free(folder);
	if (obj && suggest_units)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	start_debug(t_config tester, char *units_tests)
{
	char	*traces_folder;

	read_source(tester.folder, units_tests);
	exec_units(tester);
	traces_folder = append_to_str(tester.workdir, "/42pool-tester");
	if (clean_workdir(traces_folder) != EXIT_FAILURE)
		fprintf(stderr, "Somethings went wrong when trying to clean up working\
 directory");
	if (traces_folder)
		free(traces_folder);
	return (EXIT_SUCCESS);
}
