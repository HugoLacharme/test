#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "test.h"


int main(void) 
{
	int a = 0;
	print(a);
	printf("salut\n");
	/*//int fd;
	char buff[100];
	system("gcc -g -Wall test2.c");
	//fd = open(2,O_RDONLY);

	while (1) {
		read(2,buff,99);
		printf("%s\n",buff);
	}*/
	return (0);
}