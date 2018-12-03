#include "corrector.h"

FILE *compile(int ac, char **av)
{
	int tmp;
	FILE *fd = fopen("correction.txt","w+");
	assert(fd != NULL);

	tmp = fork();
	if (tmp < 0)
		return (0);
	if (tmp != 0) {
		wait(0);
	} else {
		dup2(fileno(fd),fileno(stderr));
		av[0] = "gcc";
		execvp(av[0],av);
		perror("sa marche pas a léde");
		exit(1);
	}
	return (fd);
}