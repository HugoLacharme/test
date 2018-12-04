#include "corrector.h"

void freeFiles(cor f, int ac)
{
	for (int i  = 0; i < ac-1; i++) {
		free(f.files[i].name);
		fclose(f.files[i].fd);
	}
	fclose(f.fd_cor);
	free(f.files);
}

void free_lines(char **lines)
{
	char **temp = lines;

	while (*lines != NULL)
		free(*lines++);
	free(temp);
}

void free_struct(errt *err)
{
	errt *temp = err;

	while (temp != NULL) {
		err = err->next;
		for (int i = 0; temp->std_err[i] != NULL; i++)
			free(temp->std_err[i]);
		free(temp->std_err);
		free(temp->function);
		free(temp);
		temp = err;
	}
}