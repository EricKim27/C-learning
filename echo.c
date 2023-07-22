#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("incorrect option\n");
		printf("How to use: echo '<words you want to say>'\n");
		return 1;
	}
	if(*argv[1] == "--help"){
		printf("How to use: echo '<words you want to say>'\n");
		return 20;
	}
	printf(argv[1]);
	printf("\n");
	return 0;
	}
