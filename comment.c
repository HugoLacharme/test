#include "corrector.h"

void comment(errt a){
	char* buf = "/*Salut on a corrigé ici*/";
	lseek(fileno(a.file.fd),a.ligne,SEEK_SET);
	int t = write(a.file.fd,buf,sizeof(buf));
	if(t < 0){
		perror("write");
	}
}