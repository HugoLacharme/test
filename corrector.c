#include "corrector.h"

int main(int ac, char **av)
{
	cor files;
	errt *errors;
	if (ac < 2) {
		perror("error syntaxe : ./corrector [files]");
		return (1);
	}
	files.fd_cor = compile(ac,av);
	files.files = openfiles(ac,av);
	files.nb_files = ac-1;

	errors = parseur(files);

	freeFiles(files.files, ac);
	fclose(files.fd_cor);
	return (0);
}