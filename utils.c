#include "corrector.h"

void *my_malloc(size_t size)
{
	void *new = malloc(sizeof(*new) * size);
	assert(new);
	return (new);
}

char *cut(char *str, int size)
{
	int i;
	if (size > strlen(str))
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
		printf("file : %s, :%d:%d\n",err->file.name,err->ligne, err->cur);
		err = err->next;
	}
}