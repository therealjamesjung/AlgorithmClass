#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int *arr, int left, int right)
{
    int pivot = arr[(left + right) / 2];
    int l = left, r = right;

    if (right - left < 1) return;

    while (l < r)
    {
        while (arr[l] < pivot) l++;
        while (arr[r] > pivot) r--;

        if (l <= r) swap(&arr[l++], &arr[r--]);
    }

    quick_sort(arr, left, r);
    quick_sort(arr, l, right);
}

int main()
{
    int *arr;
    int n, i;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    quick_sort(arr, 0, n - 1);
    for (i = 0; i < n; i++) printf(" %d", arr[i]);

    free(arr);

    return 0;
}