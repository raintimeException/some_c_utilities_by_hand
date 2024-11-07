#include <stdio.h>
#include "alloca.c"

int main(void)
{
        char *p = _alloca(1);
        p = "hola mundo";
        printf("%s\n", p);
        _afree(p);
        char *p2 = _alloca(1);
        p2 = "adios mundo";
        printf("%s\n", p2);
        _afree(p2);
        char *p3 = _alloca(10);
        printf("%s\n", p3);
        _afree(p3);
        return (0);
}
