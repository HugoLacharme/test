#include "corrector.h"

int sil(char *line)
{
	int i = 0;

	while (line[i] != ' ')
		i++;
	return (i);
}

int check_line(char *line, char *file)
{
	char *temp;
	if (strlen (line) < strlen(file))
		return (0);
	temp = cut(line,strlen(file));
	if (strcmp(temp,file) == 0)
		if (sil(line + strlen(file)) > 2) {
			free(temp);
			return (1);
		}
	free(temp);
	return (0);
}

int get_number(char *temp)
{
	int i;
	if ((i = atoi(strtok(temp,":"))) == 0) {
		perror("j'ai glissé chef !\n");
		exit(1);
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