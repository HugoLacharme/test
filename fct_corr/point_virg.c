#include "../corrector.h"

int semicolon(errt *a)
{
	char* buf = ";";
	int i = find_line(a);

	lseek(fileno(a->file.fd),i, SEEK_SET);
	if (fwrite(buf,1,1,a->file.fd) == 0) {
		perror("fwrite");
	}
	return (0);
}

int find_semicolon(errt *err)
{
	if (strstr(err->std_err[0], "error: expected ‘;’") != NULL)
		return (1);
	return (0);
}