#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int square(int number, int sq);

int main(int argc, char *argv[]){
  uint64_t result;
  if(argc < 3){
    printf("Syntax error!\n");
    return 1;
  }
  unsigned long num1 = atoi(argv[1]);
  unsigned long num2 = atoi(argv[2]);
  result = square(num1, num2);
  printf("the result is %" PRIu64 "\n" , result);
  return 0;
}

int square(int number, int sq){
  uint64_t tmpresult = 1;
  if(sq == 0){
    return tmpresult;
  }
  while(sq > 0){
    tmpresult *= number;
    sq--;
  }
  return tmpresult;
}
