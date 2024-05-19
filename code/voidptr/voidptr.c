#include "voidptr.h"
#include <stdlib.h>

void *some_function(int a, int b)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    if(res != NULL)
    {
        res[0] = a;
        res[1] = b;
    }
    return res;
}