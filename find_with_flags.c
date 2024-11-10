#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

int _getline(char *line, int lim)
{
        int c;
        char *pl = line;

        while ((c = getchar()) != EOF && c != '\n' && --lim > 0)
                *line++ = c;
        if (c == '\n')
                *line++ = c;
        *line = '\0';
        return (line - pl);
}

int main(int argc, char **argv)
{
        char line[MAXLINE];
        long lineno = 0;
        int c, except = 0, number = 0, found = 0;

        while (--argc > 0 && **++argv == '-') {
                while (c = *++argv[0]) {
                        switch (c) {
                                case 'x': except = 1; break;
                                case 'n': number = 1; break;
                                default: printf("Illegal option\n");
                                        argc = 0, found = -1;
                                        break;
                        }
                }
        }
        if (argc != 1)
                printf("error: usage 'found -x -n pattern'\n");
        else
                while (_getline(line, MAXLINE) > 0) {
                        lineno++;
                        if ((strstr(line, *argv) != NULL) != except) {
                                if (number)
                                        printf("%ld:", lineno);
                                printf("%s", line);
                                found++;
                        }
                }
        return (found);
}
