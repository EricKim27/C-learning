#include <stdio.h>
#define MAX_LENGTH 1024

int main(int argc, char *argv[]){
	FILE *fp = fopen(argv[2], "r");
	if(argc != 3){
		fprintf(stderr, "fgrep <number of words> <filename> \n");
		return 1;
	}
	if(fp == NULL){
		fprintf(stderr, "File was unable to be opened. \n");
		return 2;
	}
	int a;
	sscanf(argv[1], "%d", &a);
	char word[MAX_LENGTH];
	for(int i=0; i < a; i++){
		if(fscanf(fp, "%99s", word) == 1) {
			printf("%s", word);
		} else {
			printf("EOF \n");
			break;
		}
	} 
	printf("\n");
	fclose(fp);
	return 0;

}
