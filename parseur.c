#include "corrector.h"

char **get_lines(cor a)
{
	char *line = NULL;
	//char **lines = malloc(sizeof(char *) *10);
	size_t len = 0;
	ssize_t read;

	a.fd_cor = freopen("correction.txt", "r", a.fd_cor);
	assert(a.fd_cor != NULL);
	while ((read = getline(&line, &len, a.fd_cor)) != -1) {
		printf("%s", line);
	}
}

errt *parseur(cor a)
{
	errt *errtab;
	char **text;

	get_next_line(a);
	return (errtab);
}