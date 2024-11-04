#include <stdio.h>

int binsearch(int x, int v[], int lim)
{
        int mid;
        int low = 0;
        int high = lim - 1;

        while (low <= high) {
                mid = (low + high) / 2;
                if (x > v[mid])
                        low = mid + 1;
                else if (x < v[mid])
                        high = mid - 1;
                else
                        return (mid);
        }
        return (-1);
}

int main(void)
{
        int x = 100;
        int size = 100;
        int v[size];

        for (int i = 0; i < size; ++i)
                v[i] = i * i;
        printf("%d\n", binsearch(x, v, size));
        return (0);
}
