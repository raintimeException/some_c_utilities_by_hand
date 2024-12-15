/* Ivan Kovalenko */
#include <stdio.h>

#define LOG(guard, format, ...) \
        if (guard) printf("%s:%d\t" format "\n", __FILE__, __LINE__, __VA_ARGS__)

#define IS_LOGGING 1

int lookup(char *, char **);
int _strcmp(const char *s1,const char *s2);

int main(int argc, char **argv)
{
        if (*++argv == NULL) {
                LOG(IS_LOGGING, "%s", "usage: $> program_name 'lookup word'");
                return 1;
        }
        char *arr_strings[] = {
                "hi",
                "hello",
                "good bye",
                NULL
        };
        LOG(IS_LOGGING, "the word: %s is in the position: %d", *argv, lookup(*argv, arr_strings));
        return 0;
}

int lookup(char *s, char **arr)
{
        int i;

        for (i=0; arr[i] != NULL; ++i) {
                if (_strcmp(s, arr[i]) == 0)
                        return i;
        }
        return -1;
}

int _strcmp(const char *s1, const char *s2)
{
        while (*s1) {
                if (*s1 != *s2) break;
                s1++;
                s2++;
        }
        return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}
