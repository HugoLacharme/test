#include "corrector.h"

void freeFiles(fd_f *f, int ac)
{
	for(int i  = 0 ; i<ac-1 ; i++){
		free(f[i].name);
		fclose(f[i].fd);
	}
	free(f);
}

void free_lines(char **lines)
{
	char **temp = lines;

	while(*lines != NULL)
		free(*lines++);
	free(temp);
}

void free_struct(errt *err)
{
	errt *temp = err;

	while (temp != NULL) {
		err = err->next;
		free(temp);
		temp = err;
	}
}