#include "../includes/ft_tester.h"

static t_config	init_tester(char **args, int count)
{
	t_config	tester;
	int			option;

	option = getopt(count, args, "no:a:");
	while (option != -1)
	{
		if (option == 'a')
			tester.start_norminette = 1;
		else if (option == 'o')
			tester.output = optarg;
		else
		{
			tester.workdir = NULL;
			tester.output = NULL;
			break ;
		}
		option = getopt(count, args, "no:a:");
	}
	tester.workdir = args[optind];
	return (tester);
}

static DIR	*open_workdir(char *path)
{
	DIR	*workdir;

	if (!path)
		return (NULL);
	workdir = opendir(path);
	if (workdir)
		return (workdir);
	else if (ENOENT == errno)
		perror("Working directory");
	else
		fprintf(stderr, \
		"An error occurs when trying opening working directory.\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_config	tester;

	if (argc < 2 || argc > 4)
	{
		puts(HELP_MSG);
		return (EXIT_FAILURE);
	}
	tester = init_tester(argv, argc);
	tester.folder = open_workdir(tester.workdir);
	if (!tester.folder)
		return (EXIT_FAILURE);
	start_debug(tester, NULL); // need units test file
	closedir(tester.folder);
	return (EXIT_SUCCESS);
}
