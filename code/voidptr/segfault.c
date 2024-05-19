#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = (int *)malloc(sizeof(int) * 2);
    a[0] = 3;
    a[1] = 5;
    int *b = &a + 3;
    printf("%d, %d, %d", a[0], a[1], b);
    int c = a[2];
    printf(c);
    free(a);
    return 0;
}
