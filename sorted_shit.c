#include <stdio.h>

#define ARR_SIZE(arr)           (sizeof(arr)/sizeof(arr[0]))

int bisearch(char *, char *[], int);
int _strcmp(const char *, const char *);

int main(void)
{
        char *arr[] = { "a", "b", "c", "d", "e" };
        char *elem = "e";
        printf("%d\n", ARR_SIZE(arr));
        int pos = bisearch(elem, arr, ARR_SIZE(arr));
        printf("'%s' is in the position: %d\n", elem, pos);
        return 0;
}

int bisearch(char *elem, char *arr[], int lim)
{
        int com, mid, low = 0, hi = lim - 1;

        while (low <= hi) {
                mid = (low + hi) / 2;
                com = _strcmp(elem, arr[mid]);
                        if (com > 0)
                                low = mid + 1;
                        else if(com < 0)
                                hi = mid - 1;
                        else
                                return mid;
        }
        return -1;
}

int _strcmp(const char *s1, const char *s2)
{
        while (*s1) {
                if (*s1 != *s2)
                        break;
                s1++;
                s2++;
        }
        return *(const unsigned char *)s1 - *(const unsigned char *) s2;
}
