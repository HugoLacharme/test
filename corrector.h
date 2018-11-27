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

typedef struct fd_files {
	int fd;
	char *name;
} fd_f;

typedef struct corec_t {
	int fd_cor;
	fd_f *files;

} cor;

typedef struct error_t{
	fd_f file;
	int ligne;
	int cur;
	int fct_err;
}errt;

int compile(int ac, char **av);
fd_f *openfiles(int ac, char **av);
void freeFiles(fd_f *f, int ac);
errt *parseur(cor);

#endif