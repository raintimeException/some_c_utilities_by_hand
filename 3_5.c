#include <stdio.h>


char *_strcat(char *s, char *t)
{
        for ( ; *s != '\0'; s++)
                ;
        for ( ; *s = *t; s++, t++)
                ;
        return (&s[0]);
}


int main(void)
{
        char astring[1024] = "hi";
        char *pstring = "hi";
        _strcat(astring, pstring);
        printf("%s\n", pstring);
        printf("%s\n", astring);
        return (0);
}
