#include "corrector.h"

ssize_t find_line(errt* a)
{
	void * buf;
	char* gline = NULL;
	ssize_t x, nbchar = 0;
	size_t len = 0;
	printf("ligne : %d, cur : %d\n",a->ligne, a->cur);
	a->file.fd = freopen(a->file.name,"r",a->file.fd);
	for(int i = 1 ; i < a->ligne; i++) {
		nbchar = nbchar + getline(&gline, &len, a->file.fd);
	}
	x = nbchar + a->cur;
	a->file.fd = freopen(a->file.name,"r+",a->file.fd);
	return (x - 2);	
}