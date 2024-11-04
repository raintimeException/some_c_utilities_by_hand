#include <stdio.h>

void printd(int n)
{
        if (n < 0) {
                putchar('-');
                n *= -1;
        }
        if (n / 10)
                printd(n / 10);
        putchar(n % 10 + '0');
}

int main(void)
{
        printd(-123456);
        return (0);
}
