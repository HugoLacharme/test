#include "corrector.h"

void semicolon(errt a)
{
	char* buf = ";";
	
	lseek(fileno(a.file.fd),a.ligne,a.cur);
	if (fwrite(buf,1,sizeof(buf),a.file.fd) < 0) {
		perror("fwrite");
	}
}

int find_semicolon(char **lines, int start, int end, errt err)
{
	
}