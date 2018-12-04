#include "corrector.h"
ssize_t find_line(errt* a){
	a->file.fd = freopen(a->file.name,"w",a->file.fd);
	void * buf;
	char* gline = NULL;
	ssize_t nbchar = 0;
	size_t len = 0;
	for(int i = 0 ; i < a->ligne ; i++){
		nbchar = nbchar + getline(&gline, &len, a->file.fd);
	}
	ssize_t x = nbchar + a->cur;
	return (x);	
}