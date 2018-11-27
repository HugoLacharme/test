#include "corrector.h"

void get_next_line(cor a)
{
	
	char *line = NULL;
	//char **lines = malloc(sizeof(char **) *10);
	size_t len = 0;
	ssize_t read;

	//fp = fopen("correc.txt", "r");
	if (a.fd_cor == NULL)
		exit(EXIT_FAILURE);

	while ((read = getline(&line, &len, a.fd_cor)) != -1) {
		printf("%s", line);

	}
	if (line)
		free(line);

	exit(EXIT_SUCCESS);
}

errt parseur(cor a)
{
	errt errtab;
	
	get_next_line(a);
	return (errtab);
}