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
	if (a.fd_cor == NULL) {
		perror("can't open my file ? wut??");
		exit(EXIT_FAILURE);
	}
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

errt *split_error(char **lines, int start, int end, fd_f file)
{
	int start_e = start, end_e = start;
	errt *err = NULL;
	char *temp, *function = NULL, *error = strdup("test"); // strcmp sa segfault cpas cool #jaipaseudautreidé

	for (int i = start; (lines[i] != NULL) && (i < end); i++, end_e++) {
		if (check_line(lines[i], file.name, &function)) {
			temp = lines[i] + strlen(file.name);
			temp = cut(temp,sil(temp));
			if ((strcmp(temp,error) != 0)) {
				free(error);
				error = strdup(temp);
				add_std_err(err, get_stderr(lines, start_e, end_e));
				err = add_to_struct(err,creat_struct_error(file, error, function));
				start_e = end_e;
			}
			free(temp);
		}
	}
	if (strcmp(error,"test") != 0) {
		add_std_err(err, get_stderr(lines, start_e, end_e));
		free(function);
	}
	free(error);
	return (err);
}

errt *get_error(char **lines, cor a)
{
	int i = 0, start = 0, end = 0;
	char **lerr;
	errt *err = NULL;

	for (; (lines[end] != NULL) && (i <= a.nb_files); end++) { // pour chaque ligne dans correc.txt
		if (file_comp(a.files[i], a.files,lines[end], a.nb_files)) { // si a la ligne line[end] il n'y a plus a.file[i]
			err = add_to_struct(err, split_error(lines, start,end, a.files[i]));
			start = end;
			i++;
		}
	}
	err = add_to_struct(err, split_error(lines, start, end, a.files[i]));

	return (err);
}

errt *parseur(cor a)
{
	errt *errtab;
	char **text;

	text = get_lines(a);
	errtab = get_error(text,a);
	find_errors(errtab);
	free_lines(text);
	//affiche_struct(errtab);
	return (errtab);
}