#include "corrector.h"

fd_f *openfiles(int ac, char **av)
{
	fd_f *files = my_malloc(sizeof(*files) * ac);
	for (int i = 0; i < ac-1; i++) {
		files[i].name = strdup(av[i+1]);
		files[i].fd = fopen(files[i].name,"r+");
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