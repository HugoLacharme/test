#include "corrector.h"

fd_f *openfiles(int ac, char **av)
{
	fd_f *files = malloc(sizeof(fd_f*) * (ac-1));
	for (int i = 0; i < ac-1; i++) {
		files[i].fd = fopen(av[i+1],"w+");
		files[i].name = strdup(av[i+1]);
	}
	return (files);
}

void freeFiles(fd_f *f, int ac)
{
	for(int i  = 0 ; i<ac-1 ; i++){
		free(f[i].name);
		fclose(f[i].fd);
	}
	free(f);
}