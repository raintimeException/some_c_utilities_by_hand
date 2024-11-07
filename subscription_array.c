#include <stdio.h>

int main(void)
{
        int size = 10;
        int arr[size];
        int *pa;

        for (int i = 0; i < size; ++i) {
                *(arr + i) = i;
                printf("%d\n", *(arr + i));
        }
        pa = &arr[0];
        for (int i = 0; i < size + size; ++i)
                printf("%d\n", *(pa + i));
        return (0);
}
