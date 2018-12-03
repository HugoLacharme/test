#include "corrector.h"

char **get_lines(cor a)
{
	char *gline = NULL;
	char **lines = malloc(sizeof(char *) *10);
	char **temp;
	int re_alloc = 0;
	int i;
	size_t len = 0;
	ssize_t read;

	a.fd_cor = freopen("correction.txt", "r", a.fd_cor);
	assert(a.fd_cor != NULL);
	for (i = 0;(read = getline(&gline, &len, a.fd_cor)) != -1; i++, re_alloc++) {
		lines[i] = strdup(gline);
		if (re_alloc >= 9) {
			re_alloc = 0;
			temp = malloc(sizeof(*temp) * (i + 10));
			memcpy(temp,lines, (i+1) * sizeof(*lines));
			free(lines);
			lines = temp;
		}
	}
	free(gline);
	lines[i] = NULL;
	return (lines);
}

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

errt *creat_struct_err(char **lines, int start, int end, fd_f file)
{
	errt *err;
	char *temp;

	for (int i = 0; (lines[i] != NULL); i++) {
		if (check_line(lines[i], file.name)) {
			temp = lines[i] + strlen(file.name);
			temp = cut(temp,sil(temp));
			printf("%s\n",temp);
			free(temp);
		}
	}
	return (err);
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

errt *get_error(char **lines, cor a)
{
	int i = 0, start = 0, end = 0;
	char **lerr;
	errt *err;

	for (; (lines[end] != NULL) && (i <= a.nb_files); end++) { // pour chaque ligne dans correc.txt
		if (file_comp(a.files[i], a.files,lines[end], a.nb_files)) { // si a la ligne line[end] il n'y a plus a.file[i]
			//err = add_to_struct(
				creat_struct_err(lines, start,end, a.files[i]);
			start = end + 1;
			i++;
		}
	}
	//err = add_to_struct(creat_struct_err(lines, start,end, a.files[i]));

	return (err);
}
errt *parseur(cor a)
{
	errt *errtab;
	char **text;

	text = get_lines(a);
	errtab = get_error(text,a);
	free_lines(text);
	return (errtab);
}