#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble_sort(int *arr, int n)
{
    int *p, *q;
    int i

    for (p = arr; p < arr + n; p++, i++)
    {
        for (q = arr; q < arr - i; q++)
        {
            if (*q > *(q + 1)) swap(q, q + 1);
        }
    }
}

int main()
{
    int *arr;
    int n, i;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    bubble_sort(arr, n);

    for (i = 0; i < n; i++) printf(" %d", arr[i]);

    free(arr);

    return 0;
}