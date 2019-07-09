#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int right)
{
    int *tmp;
    int n = (right - left + 1);
    int mid = (left + right) / 2 + 1;
    int i = 0, l = left, m = mid;

    tmp = (int *)malloc(sizeof(int) * n);

    while (l < mid && m <= right)
    {
        if (arr[l] > arr[m]) tmp[i++] = arr[m++];
        else tmp[i++] = arr[l++];
    }

    while (l < mid) tmp[i++] = arr[l++];

    while (m <= right) tmp[i++] = arr[m++];

    for (i = 0; i < n; i++) arr[left++] = tmp[i];
    free(tmp);
}

void merge_sort(int *arr, int left, int right)
{
    int mid = (left + right) / 2;

    if (right - left < 1) return;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, right);
}

int main()
{
    int *arr;
    int n, i;

    scanf("%d", &n);

    arr = (int *)malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    merge_sort(arr, 0, n - 1);
    for (i = 0; i < n; i++) printf(" %d", arr[i]);

    free(arr);

    return 0;
}