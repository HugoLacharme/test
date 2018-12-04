#include "corrector.h"

void *my_malloc(size_t size)
{
	void *new = malloc(sizeof(*new) * size);
	if (new == NULL) {
		perror("malloc fail !");
		exit(EXIT_FAILURE);
	}
	return (new);
}

char *cut(char *str, int size)
{
	int i;
	if ((unsigned int)size > strlen(str))
		return (NULL);
	char *new = my_malloc(sizeof(*new) * (size + 1));

	for(i = 0; i < size; i++)
		new[i] = str[i];
	new[i] = '\0';
	return (new);
}

void affiche_struct(errt *err)
{
	while (err != NULL) {
		printf("file : %s, In function : %s :%d:%d \n",err->file.name, err->function, err->ligne, err->cur);
		//for (int i = 0; err->std_err[i] != NULL; i++)
			//printf("%s",err->std_err[i]);
		err = err->next;
	}
}