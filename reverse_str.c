#include <stdio.h>

int _strlen(char *s)
{
        int i;

        for (i = 0; s[i] != '\0'; ++i)
                ;
        return (i);
}

void reverse(char *s)
{
        for (int i = 0, c, j = _strlen(s) - 1; s[i] != '\0'; i++)
                c = s[i], s[i] = s[j], s[j] = c;
}

int main(void)
{
        char s[] = "h3ll0";
        printf("%s\n", s);
        reverse(s);
        printf("%s\n", s);
        return (0);
}
