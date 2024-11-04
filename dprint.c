#include <stdio.h>

#define dprint(expr)    printf(#expr " = %d\n", expr)
#define fprint(expr)    printf(#expr " = %.8f\n", expr)

int main(void)
{
        int x = 10;
        int y = 2;
        dprint(x/y);
        {
                double x = 10.0;
                double y = 2.0;
                fprint(x/y);
        }
        return (0);
}
