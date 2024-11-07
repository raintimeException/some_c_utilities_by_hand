#include <stdio.h>
#include <ctype.h>

#define SIZE    10

char buf[SIZE];
int bufp = 0;

int main(void)
{
        int i, array[SIZE], getint(int *);

        for (i = 0; i < SIZE && getint(&array[i]) != EOF; ++i)
                ;
        for (i = 0; i < SIZE; ++i)
                printf("%d\n", array[i]);
        return (0);
}

int getch(void)
{
        return ((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
        if (bufp >= SIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}

int getint(int *pi)
{
        int c, sign;

        while (isspace(c = getch()))
                ;
        if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
                ungetch(c);
                return (0);
        }
        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-') {
                int ch = getch();
                if (!isdigit(ch)) {
                        if (ch != EOF) {
                                ungetch(ch);
                        }
                }
                c = getch();
        }
        for (*pi = 0; isdigit(c); c = getch())
                *pi = *pi * 10 + (c - '0');
        *pi *= sign;
        if (c != EOF)
                ungetch(c);
        return (c);
}
