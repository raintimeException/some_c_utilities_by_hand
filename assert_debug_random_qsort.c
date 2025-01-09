#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG
// #undef DEBUG    /* turns off debugging */

#ifdef DEBUG
#   define D(x) x
#else
#   define D(x)    /* empty */
#endif

#ifdef DEBUG
#   define ASSERT(condition, msg)\
        if ( !(condition) ) {\
            fprintf(stderr, "ASSERT (" #condition ") FAILED"\
                    "[File: " __FILE__ ", Line: %d]\n\t%s\n",\
                    __LINE__, (msg));\
            exit(-1);\
        }
#else
#   define ASSERT(cnd, msg)    /* empty */
#endif

static const int N = 10;

void swap(int *arr, int i, int j)
{
    int t;

    t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void quicksort(int *arr, int lim)
{
    int i, last;

    if (lim <= 1) goto exit;
    swap(arr, 0, arc4random_uniform(lim));
    last = 0;
    for (i = 1; i < lim; ++i)
        if (arr[0] > arr[i])
            swap(arr, ++last, i);
    swap(arr, 0, last);
    quicksort(arr, last);
    quicksort(arr+last+1, lim-last-1);
exit: return;
}

int main(void)
{
    int i, *arr = (int *) malloc(N*sizeof(int));
    unsigned short manual_random_insert = 1;

    ASSERT(arr, "main(): Unexpected NULL, can't allocate memory");
    D(fprintf(stdout, "%s\n", "Memory allocated"));
    // uint32_t arc4random_uniform(uint32_t upper_bound); maybe i need an upper_bound...
    D(fprintf(stdout, "\n%s%s\n", manual_random_insert ? "YES," : "NO", " manual insertion"));

    if(!manual_random_insert) arc4random_buf(arr, N*sizeof(int));

    for (i = 0; i < N; ++i) {
        if(manual_random_insert) arr[i] = arc4random_uniform(N);
        D(fprintf(stdout, (i != N-1) ? " %d" : " %d\n", arr[i]));
    }
    quicksort(arr, N);
    for (i = 0; i < N; ++i) {
        D(fprintf(stdout, (i != N-1) ? " %d" : " %d\n", arr[i]));
    }
    free(arr);
    return 0;
}
