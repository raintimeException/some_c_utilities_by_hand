#include <stdio.h>

#define dprintf(e)      printf(#e " returns value: %d\n", e)

static inline int foo(void)
{
        return 0;
}

int main(void)
{
        (void)dprintf(foo());
        return 0;
}
