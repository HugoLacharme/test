#include "../corrector.h"

int semicolon(errt *a)
{
	char* buf = ";";
	int i = find_line(a);
	printf("%d\n",i);
	lseek(fileno(a->file.fd),i, SEEK_SET);
	if (fwrite(buf,1,1,a->file.fd) < 0) {
		perror("fwrite");
	}
}

int find_semicolon(errt *err)
{
	if (strstr(err->std_err[0], "error: expected ‘;’") != NULL)
		return (1);
	return (0);
}