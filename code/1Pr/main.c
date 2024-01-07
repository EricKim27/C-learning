#include <stdio.h>

int calculate(int a, int b);

int main(void){
	int a;
	int b;
	int c;
	printf("Input first number: ");
	scanf("%d", &a);
	printf("Input second number: ");
	scanf("%d", &b);
	c = calculate(a, b);
	printf("the answer is %d \n", c);
	return 0;
}
int calculate(int a, int b) {
	int result;
	result = a + b;
	return result;
}
