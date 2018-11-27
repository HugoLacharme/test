#include "corrector.h"

FILE *compile(int ac, char **av)
{
	FILE *fd = fopen("correc.txt","w+");
	dup2(fileno(fd),fileno(stderr));

	int tmp = fork();
	if (tmp < 0)
		return (0);
	if (tmp != 0) {
		while(wait(0)!=tmp);
	} else {
		av[0] = "gcc";
		execvp(av[0],av);
		perror("sa marche pas a léde");
		exit(1);
	}
	return (fd);
}