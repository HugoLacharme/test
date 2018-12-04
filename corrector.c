#include "corrector.h"

void corrector(errt *err)
{
	int (**fc)(errt *err);

	fc = get_tab_corrector();
	while (err != NULL) {
		(*fc[err->fct_err])(err);
		err = err ->next;
	}
}

int main(int ac, char **av)
{
	cor files;
	errt *errors;
	if (ac < 2) {
		fprintf(stderr,"error syntaxe : ./corrector [files]\n");
		return (1);
	}
	files.fd_cor = compile(ac,av);
	files.files = openfiles(ac,av);
	files.nb_files = ac-1;

	errors = parseur(files);
	corrector(errors);

	freeFiles(files, ac);
	free_struct(errors);
	
	return (0);
}