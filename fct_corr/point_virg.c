#include "corrector.h"

void point_virg(errt a){
	char* buf = ";";
	
	lseek(fileno(a.file.fd),a.ligne,a.cur);
	if (fwrite(buf,1,sizeof(buf),a.file.fd) < 0) {
		perror("fwrite");
	}
}