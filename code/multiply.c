#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if(argc != 3){
    printf("Error\n");
    printf("how to use: multiply <first number> <second number>\n");
    return 1;
  }
  int a, b;
  sscanf(argv[1], "%d", &a);
  sscanf(argv[2], "%d", &b);
  printf("The answer is %d \n", a * b);
  return 0;
}
