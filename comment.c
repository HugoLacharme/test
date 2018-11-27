#include "corrector.h"

void comment(errt a)
{
	char* buf = "/*Salut on a corrigé ici*/";
	
	lseek(fileno(a.file.fd),a.ligne,SEEK_SET);
	if (fwrite(buf,1,sizeof(buf),a.file.fd) < 0) {
		perror("fwrite");
	}
}