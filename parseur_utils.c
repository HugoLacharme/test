#include "corrector.h"

int sil(char *line)
{
	int i = 0;

	while (line[i] != ' ')
		i++;
	return (i);
}

char *find_function(char *line, char **fc)
{
	char *function = *fc;
	if (strstr(line, "In function") != NULL) {
		strtok(line, "‘");
		function = strdup(strtok(NULL, "‘"));
	} else if (strstr(line, "At top level") != NULL) {
		function = strdup("At top level");
	}
	return (function);
}

int check_line(char *line, char *file, char **function)
{
	char *temp;
	if (strlen(line) < strlen(file))
		return (0);
	temp = cut(line,strlen(file));
	if (strcmp(temp,file) == 0)
		if (sil(line + strlen(file)) > 2) {
			free(temp);
			return (1);
		} else {
			if (*function != NULL) 
				free(*function);
			*function = find_function(line, function);
		}
	free(temp);
	return (0);
}

int get_number(char *temp)
{
	int i;
	if ((i = atoi(strtok(temp,":"))) == 0) {
		perror("j'ai glissé chef !\n");
		exit(EXIT_FAILURE);
	}
	return (i);
}

int file_comp(fd_f file, fd_f *other, char *line, int nb_files)
{
	char *temp;
	for (int i = 0; i < nb_files; i++) {
		if ((temp = cut(line,strlen(other[i].name))) != NULL) {
			if ((strcmp(other[i].name, temp) == 0) 
			&& (other[i].name != file.name)) {
				free(temp);
				return (1);
			}
			free(temp);
		}
	}
	return (0);
}