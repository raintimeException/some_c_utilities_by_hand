#include <stdio.h>

#define swap(t,x,y)     (t = x, x = y, y = t)

void _swap(int *px, int *py)
{
        int t;

        t = *px;
        *px = *py;
        *py = t;
}

int main(void)
{
        int x = 1, y = 2, t = 0;
        printf("x: %d, y: %d\n", x, y);
        swap(t, x, y);
        printf("x: %d, y: %d\n", x, y);
        _swap(&x, &y);
        printf("x: %d, y: %d\n", x, y);
        return (0);
}
