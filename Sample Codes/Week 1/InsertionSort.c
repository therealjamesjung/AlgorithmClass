#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n)
{
    int tmp;
    int *p, *q;

    for (p = arr + 1; p < arr + n; p++)
    {
        tmp = *p;
        for (q = p; q > arr; q--)
        {
            if (*(q - 1) < tmp) break;
            *q = *(q - 1);
        }
        *q = tmp;
    }
}

int main()
{
    int *arr;
    int n, i;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    insertion_sort(arr, n);

    for (i = 0; i < n; i++) printf(" %d", arr[i]);

    free(arr);

    return 0;
}