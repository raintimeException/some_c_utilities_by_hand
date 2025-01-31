#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 1000
#define MAXLEN MAXLINES
char *lineptr[MAXLINES];

int _getline(char line[], int lim)
{
        int c, i;

        i = 0;
        while ((c = getchar()) != EOF && c != '\n' && --lim > 0)
                line[i++] = c;
        if (c == '\n')
                line[i++] = c;
        line[i] = '\0';
        return (i);
}

int readlines(char *lineptr[], int lim)
{
        int len, nlines, ip;
        char line[MAXLEN], *p;

        nlines = 0;
        while ((len = _getline(line, lim)) > 0) {
                if (nlines >= lim || ((p = (char *)malloc(len)) == NULL)) {
                        return (-1);
                } else {
                        strcpy(p, line);
                        lineptr[nlines++] = p;
                }
        }
        return (nlines);
}


void swap(char *v[], int i, int j)
{
        char *t;
        t = v[i], v[i] = v[j], v[j] = t;
}


void _qsort(char *v[], int left, int right)
{
        int i, last;

        if (left >= right)
                return;
        swap(v, left, (left + right) / 2);
        last = left;
        for (i = left + 1; i <= right; i++)
                if (strcmp(v[i], v[left]) < 0)
                        swap(v, ++last, i);
        swap(v, left, last);
        _qsort(v, left, last - 1);
        _qsort(v, last + 1, right);
}

void writelines(char *lineptr[], int nlines)
{
        while (nlines-- > 0)
                printf("%s", *lineptr++);
}


int main(void)
{
        int nlines;

        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
                _qsort(lineptr, 0, nlines - 1);
                writelines(lineptr, nlines);
                return (0);
        } else {
                printf("error: too many lines\n");
                return (1);
        }
        return (0);
}
