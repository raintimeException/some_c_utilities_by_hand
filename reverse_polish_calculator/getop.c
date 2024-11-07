#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getop(char s[])
{
        int i, c;

        while ((s[0] = c = getch()) == ' ' || c == '\t')
                ;
        s[1] = '\0';
        if (!isdigit(c) && c != '.')
                return (c);
        i = 0;
        if (isdigit(c))
                while (isdigit(s[++i] = c = getch()))
                        ;
        if (c == '.')
                while (isdigit(s[++i] = c = getch()))
                        ;
        s[i] = '\0';
        if (c != EOF) {
                if (bufp >= BUFSIZE)
                        printf("ungetch: too many characters\n");
                else
                        buf[bufp++] = c;
        }
        return (NUMBER);
}

int getch(void)
{
        return ((bufp > 0) ? buf[--bufp] : getchar());
}

