#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_COUNT_ELEMENTS 100

int bisearch(int n, int *arr, int lim)
{
    int low = 0, high = lim - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (n > arr[mid])
            low = mid + 1;
        else if (n < arr[mid])
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int _compar(const void *a, const void *b)
{
    const int *_a = a, *_b = b;
    return (*_a > *_b) - (*_a < *_b);
}

int main(void)
{
    int *haystack = (int *) malloc(ARR_COUNT_ELEMENTS*sizeof(int));
    int needle = 5;
    int i;
    srand(time((void *) 0));

    printf("insert\n");
    for (i = ARR_COUNT_ELEMENTS; i > 0; --i) {
        *(haystack + ARR_COUNT_ELEMENTS - i) = rand() % 10;
        printf("%d\n", *(haystack + ARR_COUNT_ELEMENTS - i));
    }
    printf("sort\n");
    qsort(haystack, ARR_COUNT_ELEMENTS, sizeof(int), (&_compar));
    printf("search\n");
    printf("%d\n", bisearch(needle, haystack, ARR_COUNT_ELEMENTS - 1));
    free(haystack);
    return 0;
}
