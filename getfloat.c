#include <stdio.h>
#include <ctype.h>

#define SIZE    10

char buf[SIZE];
int bufp = 0;

int main(void)
{
        int i;
        double array[SIZE], getfloat(double *);

        for (i = 0; i < SIZE && getfloat(&array[i]) != EOF; ++i)
                ;
        for (i = 0; i < SIZE; ++i)
                printf("%.8f\n", array[i]);
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

double getfloat(double *pf)
{
        int c, sign, pow;

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
        for (*pf = 0; isdigit(c); c = getch())
                *pf = *pf * 10 + (c - '0');
        if (c == '.') {
                c = getch();
        }
        for (pow = 1; isdigit(c); c = getch()) {
                *pf = *pf * 10 + (c - '0');
                pow *= 10;
        }
        *pf *= sign;
        *pf /= pow;
        if (c != EOF)
                ungetch(c);
        return (c);
}
