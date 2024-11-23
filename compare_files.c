#include <stdio.h>
#include <string.h>

#define BUF_SIZE        4096
#define dprintf(e)      printf(#e ": %d\n", e)

int main(int argc, char **argv)
{
        FILE *ifp1, *ifp2 = NULL;
        char buf1[BUF_SIZE], buf2[BUF_SIZE];
        int f1_line_c = 1, f2_line_c = 1;

        if (argc < 3) {
                printf("error: to few arguments\n");
                return 1;
        }

        ifp1 = fopen(*++argv, "r");
        if (ifp1 == NULL) {
                printf("error: can't open: %s\n", *argv);
                goto close;
                return 1;
        }

        ifp2 = fopen(*++argv, "r");
        if (ifp2 == NULL) {
                printf("error: can't open: %s\n", *argv);
                goto close;
                return 1;
        }
        for (char *s1, *s2; (s1 = fgets(buf1, BUF_SIZE*sizeof(char), ifp1)) != NULL
                        && (s2 = fgets(buf2, BUF_SIZE*sizeof(char), ifp2)) != NULL;
                        ++f1_line_c, ++f2_line_c) {
                if (strcmp(s1, s2) != 0) {
                        printf("\t%d\ts: %s\t%d\ts2: %s", f1_line_c, s1, f2_line_c, s2);
                        break;
                }
        }

close:
        if (ifp1 != NULL) dprintf(fclose(ifp1));
        if (ifp2 != NULL) dprintf(fclose(ifp2));
        return 0;
}
