#include <stdio.h>

#define MAX 1024

/* returns rightmost occurance of t in s, or -1 if there is none */
int strrindex(char *s, char *t);
int _getline(char *s, int lim);
int _strlen(char *s);

int main(void)
{
        char s[MAX];
        char *t = "hi";
        int pos;

        while (_getline(s, MAX) > 0) {
                if ((pos = strrindex(s, t)) != -1) {
                        printf("%d: %s", pos, &s[pos]);
                }
        }
        return (0);
}

int strrindex(char *s, char *t)
{
        int i, j, k, p;

        for (i = 0, p = 0; s[i] != '\0'; i++) {
                for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
                        ;
                if (k > 0 && t[k] == '\0')
                        p = i;
        }
        return ((p > 0) ? p : -1);
}

int _getline(char *s, int lim)
{
        int i, c;

        i = 0;
        while ((c = getchar()) != EOF && c != '\n')
                s[i++] = c;
        if (c == '\n')
                s[i++] = c;
        s[i] = '\0';
        return (i);
}
