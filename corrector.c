#include "corrector.h"

int main(int ac, char **av)
{
	cor files;
	errt errors;
	if (ac < 2) {
		perror("error syntaxe : ./corrector [files]");
		return (1);
	}
	files.fd_cor = compile(ac,av);
	files.files = openfiles(ac,av);

	errors = parseur(files);

	freeFiles(files.files, ac);
	return (0);
}