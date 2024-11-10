#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char *line, int max)
{
        int c;
        char *pl = line;

        line = &line[0];
        while ((c = getchar()) != EOF && c != '\n' && --max > 0)
                *line++ = c;
        if (c == '\n')
                *line++ = c;
        *line = '\0';
        return (line - pl);
}

int main(int argc, char **argv)
{
        char line[MAXLINE];
        int found = 0;

        if (argc != 2) {
                printf("error: wrong usage of find(grep) program\n");
                return (1);
        } else {
                while (_getline(line, MAXLINE) > 0)
                        if (strstr(line, argv[1]) != NULL)
                                printf("%s\n", line), found++;
        }
        return (0);
}
