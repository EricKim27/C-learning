#include "voidptr.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Usage: %s <firstval> <secval\n", argv[0]);
        return 1;
    }
    struct example e;
    e.example_function = some_function;
    int a_value = atoi(argv[1]);
    int b_value = atoi(argv[2]);
    int *a = (int *)e.example_function(a_value, b_value);
    printf("the result is %d\n", a[0]+a[1]);
    free(a);
    return 0;
}