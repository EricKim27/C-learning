#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("error\n");
		printf("how to use: add <first number> <second number>\n");
		return 1;
		}
	int a;
	int b;
	sscanf(argv[1], "%d", &a); /* changes the first value to integer */
	sscanf(argv[2], "%d", &b); /* changes the second value to integer */
	printf("The answer is %d \n", a + b);
	return 0;
	}
