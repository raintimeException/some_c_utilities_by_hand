#include <stdio.h>

char *_strncpy(char dst[], char *src, size_t n)
{
        while ((*dst++ = *src++) && --n > 0)
                ;
        return (&dst[0]);
}

char *_strncat(char *dst, char *src, size_t n)
{
        while (*++dst != '\0')
                ;
        while ((*dst++ = *src++) && --n > 0)
                ;
        *dst = '\0';
        return (0);
}

int _strncmp(char s1[], char s2[], size_t n)
{
        for (int i = 0; i < n; i++)
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
        return (0);
}

int _strlen(char *s)
{
        char *p = s;

        while (*++p)
                ;
        return (p - s);
}

int main(void)
{
        char dst[1024] = "1234";
        char *src = "12345";
        int comp =_strncmp(dst, src, _strlen(src));
        printf("%d\n", comp);
        return (0);
}
