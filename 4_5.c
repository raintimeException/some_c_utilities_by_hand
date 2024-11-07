#include <stdio.h>

int _strlen(char *s)
{
        char *p = s;
        while (*++s)
                ;
        return (s - p);
}

int _strcmp(char *s, char *t)
{
        for ( ; *s == *t; s++, t++)
                if (*s == '\0')
                        return (0);
        return (*s - *t);
}

int _strend(char *s, char *t)
{
        if (_strlen(s) < _strlen(t)) return (0);
        return (!_strcmp(s + _strlen(s) - _strlen(t), t));
}

int main(void)
{
        char *s = "string, end";
        char *t = "n";
        printf("%d\n", _strend(s, t));
        return (0);
}
