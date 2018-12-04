#include "../corrector.h"

int semicolon(errt *a)
{
	char* buf = ";";
	printf("c'est ici\n");
	lseek(fileno(a->file.fd),a->ligne a->cur, SEEK_SET);
	if (fwrite(buf,1,sizeof(buf),a->file.fd) < 0) {
		perror("fwrite");
	}
}

int find_semicolon(errt *err)
{
	if (strstr(err->std_err[0], "error: expected ‘;’") != NULL)
		return (1);
	return (0);
}