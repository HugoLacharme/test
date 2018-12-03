#include "corrector.h"

fd_f *openfiles(int ac, char **av)
{
	fd_f *files = my_malloc(sizeof(*files) * ac);
	for (int i = 0; i < ac-1; i++) {
		files[i].name = strdup(av[i+1]);
		if ((files[i].fd = fopen(files[i].name,"r+")) == NULL) {
			perror(files[i].name);
			exit(EXIT_FAILURE);
		}

	}
	return (files);
}