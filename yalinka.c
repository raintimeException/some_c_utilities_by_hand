#include <stdio.h>

int main(void)
{
        int i;
        int max = 30;

        printf("%*c\n", max/2, '*');
        for (i = 1; i < max/2; i++) {
                printf("%*c%*c\n", max/2 - i , '/', i + i, '\\');
        }
        for (i = 0; i < max; i++)
                printf("-"); printf("\n");
        for (i = 0; i < max/2/2/2; i++)
                printf("%*c%*c\n", max/2 - 1, '|', 1, '|');
        return 0;
}
