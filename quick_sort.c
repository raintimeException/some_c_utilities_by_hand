#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE(arr)           (sizeof(arr)/sizeof(arr[0]))

void quicksort(int [], int);
void swap(int [], int i, int j);

int main(void)
{
        int i;
        int arr[] = { 10, 5, 7, 3, 6, 9, 18, 93};
        for (i = 0; i < ARR_SIZE(arr); ++i) {
                printf((i != ARR_SIZE(arr) - 1) ? "%d " : "%d\n", *(arr + i));
        }
        quicksort(arr, ARR_SIZE(arr));
        printf("**********************************\n");
        for (i = 0; i < ARR_SIZE(arr); ++i) {
                printf((i != ARR_SIZE(arr) - 1) ? "%d " : "%d\n", *(arr + i));
        }
        return 0;
}

void quicksort(int arr[], int n)
{
        int i, last;

        if (n <= 1) return;
        swap(arr, 0, rand() % n);
        last = 0;
        for (i = 1; i < n; ++i)
                if (arr[i] < arr[0])
                        swap(arr, ++last, i);
        swap(arr, 0, last);
        quicksort(arr, last);
        quicksort(arr+last+1, n-last-1);
}

void swap(int arr[], int i, int j)
{
        int t = 0;

        t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
}
