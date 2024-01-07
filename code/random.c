#include <time.h>
#include <stdio.h>
int main()
{
    srand(time(NULL));
    int r = rand();
    printf(r);
	return 0;
}
