#include "corrector.h"

int compile(int ac, char **av)
{
	int fd = open("correc.txt",O_RDWR | O_CREAT);
	dup2(fd,2);

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