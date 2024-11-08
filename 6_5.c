#include <stdio.h>

#define MAX 1024

int _strlen(char *s)
{
        char *ps = s;
        while (*++s)
                ;
        return (s - ps);
}

void _reverse(char *s)
{
        char *e = s + _strlen(s);
        if (s == e) return;
        --e;
        for (int t; s < e; s++, e--)
                t = *s, *s = *e, *e = t;
}

int _getline(char *line, int lim)
{
        int c;
        char *pline = line;

        while ((c = getchar()) != EOF && c != '\n' && (--lim) > 0)
        {
                *line++ = c;
        }
        if (c == '\n')
                *line++ = c;
        *line = '\0';
        return (line - pline);
}

int _isspace(char c)
{
        return (c == ' ' || c == '\t' || c == '\n');
}

int _isdigit(char c)
{
        return (c >= '0' && c <= '9');
}

int _atoi(char *s)
{
        int sign, n;

        while (_isspace(*++s))
                ;
        sign = (*s == '-') ? -1 : 1;
        if (*s == '-' || *s == '+')
                s++;
        for (n = 0; _isdigit(*s); ++s)
                n = n * 10 + (*s - '0');
        return (n * sign);
}

void _itoa(int val, char *s)
{
        int sign, t;
        char *ps = s; //TODO: make it without this pointer

        sign = (val < 0) ? -1 : 1;
        val *= sign;
        while (val > 0) {
                t = val % 10;
                *s++ = '0' + t;
                val /= 10;
        }
        if (sign == -1)
                *s++ = '-';
        *s = '\0';
        _reverse(ps);
}

int main(void)
{
        char s[MAX];
        int val = -12345;
        printf("%s\n", s);
        _itoa(val, s);
        printf("%s\n", s);
        return (0);
}
