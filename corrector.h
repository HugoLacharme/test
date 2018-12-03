#ifndef CORRECTOR_H
#define CORRECTOR_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>

typedef struct fd_files {
	FILE *fd;
	char *name;
} fd_f;

typedef struct corec_t {
	FILE *fd_cor;
	fd_f *files;
	int nb_files;
} cor;

typedef struct error_t{
	fd_f file;
	int ligne;
	int cur;
	int fct_err;
	struct error_t *next;
}errt;

FILE *compile(int ac, char **av);
fd_f *openfiles(int ac, char **av);
void freeFiles(fd_f *f, int ac);
errt *parseur(cor);
void comment(errt a);
void free_lines(char **lines);
void *my_malloc(size_t size);
char *cut(char *str, int size);
int sil(char *line);
int check_line(char *line, char *file);
int get_number(char *temp);
int file_comp(fd_f file, fd_f *other, char *line, int nb_files);
void affiche_struct(errt *err);
void free_struct(errt *err);

#endif