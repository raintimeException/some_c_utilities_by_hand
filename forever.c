#include <stdio.h>

#define forever for(;;)

int main(void)
{
        int i = 0;
        forever {
                i++;
                printf("%d\n", i);
        }
        return (0);
}
