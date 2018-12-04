#include "corrector.h"

int get_number(char *temp)
{
	int i;
	if ((i = atoi(strtok(temp,":"))) == 0) {
		perror("j'ai glissé chef !\n");
		exit(EXIT_FAILURE);
	}
	return (i);
}

errt *add_to_struct(errt *base, errt *new)
{
	errt *temp = base;
	if (base == NULL) {
		base = new;	
	} else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new;
	}
	return (base);

}

errt *creat_struct_error(fd_f file, char *error, char *function)
{
	errt *new = my_malloc(sizeof(*new));
	char *temp = strdup(error);

	new->file = file;
	new->ligne = get_number(temp);
	new->cur = get_number(NULL);
	if (function != NULL)
		new->function = strdup(function);
	else
		new->function = NULL;
	free(temp);
	new->next = NULL;
	return (new);
}