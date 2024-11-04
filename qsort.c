#include <stdio.h>

void qsort(int v[], int l, int r)
{
        int i, last;
        void swap(int v[], int i, int j);

        if (l >= r)
                return ;
        swap(v, l, (l + r) / 2);
        last = l;
        for (i = l + 1; i <= r; ++i)
                if (v[i] < v[l])
                        swap(v, ++last, i);
        swap(v, l, last);
        qsort(v, l, last - 1);
        qsort(v, last + 1, r);
}

void swap(int v[], int i, int j)
{
        int t;

        t = v[i];
        v[i] = v[j];
        v[j] = t;
}

int main(void)
{
        int size = 2000000;
        int v[size];
        for (long i = 0, j = size; j > 0; --j, ++i)
                v[i] = j;
        printf("%d\n", v[0]);
        printf("****\n");
        qsort(v, 0, size);
        printf("%d\n", v[0]);
        return (0);
}
