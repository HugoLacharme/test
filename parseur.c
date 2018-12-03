#include "corrector.h"

char **get_lines(cor a)
{
	char *gline = NULL;
	char **lines = my_malloc(sizeof(char *) *10);
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
			temp = my_malloc(sizeof(*temp) * (i + 10));
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

void add_to_struct(errt *err, errt *new)
{
	printf("salut\n");
	errt *temp = err;
	if (err == NULL) {
		printf("salut1\n");
		err = new;
	} else {
		printf("salut2\n");
		while (temp->next != NULL) {
			temp = temp->next;
			printf("oui?\n");
		}
		printf("salut4\n");
		temp->next = new;
	}
	printf("salut5\n");

}

int get_number(char *temp)
{
	int i;
	if((i = atoi(strtok(temp,":"))) == 0) {
		perror("j'ai glissé chef !\n");
		exit(1);
	}
	return (i);
}
errt *creat_struct_error(char **lines, int start, int end, fd_f file, char *error)
{
	errt *new = malloc(sizeof(*new));
	char *temp = strdup(error);

	new->file = file;
	new->ligne = get_number(temp);
	new->cur = get_number(NULL);
	free(temp);
	//new.fct_err = find_error(lines,start,end,new);
	new->next = NULL;
	return (new);
}

errt *split_error(char **lines, int start, int end, fd_f file)
{
	int start_e = start, end_e = start;
	errt *err = NULL;
	char *temp, *error = strdup("a"); // strcmp sa segfault cpas cool #jaipaseudautreidé

	for (int i = start; (lines[i] != NULL) && (i < end); i++, end_e++) {
		if (check_line(lines[i], file.name)) {
			temp = lines[i] + strlen(file.name);
			temp = cut(temp,sil(temp));
			if ((strcmp(temp,error) != 0)) {
				free(error);
				error = strdup(temp);
				printf("ieaeazi?\n");
				add_to_struct(err, creat_struct_error(lines, start_e, end_e, file, error));
				start_e = end_e + 1;
			}
			free(temp);
		}
	}
	free(error);
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
	errt *err = NULL;

	for (; (lines[end] != NULL) && (i <= a.nb_files); end++) { // pour chaque ligne dans correc.txt
		if (file_comp(a.files[i], a.files,lines[end], a.nb_files)) { // si a la ligne line[end] il n'y a plus a.file[i]
			//printf("pas la\n");
			add_to_struct(err, split_error(lines, start,end, a.files[i]));
			start = end + 1;
			i++;
		}
	}
	add_to_struct(err, split_error(lines, start,end, a.files[i]));

	return (err);
}

void affiche_struct(errt *err)
{
	while (err->next != NULL) {
		printf("file : %s, :%d:%d\n",err->file.name,err->ligne, err->cur);
	}
}

errt *parseur(cor a)
{
	errt *errtab;
	char **text;

	text = get_lines(a);
	errtab = get_error(text,a);
	free_lines(text);
	//affiche_struct(errtab);
	return (errtab);
}