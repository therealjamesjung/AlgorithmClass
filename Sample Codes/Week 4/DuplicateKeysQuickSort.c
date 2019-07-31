#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick_sort(int arr[8][2], int left, int right)
{
    int pivot = arr[(left + right) / 2][0];
    int l = left, r = right;

    if (right - left < 1) return;

    while (l < r)
    {
        while (arr[l][0] < pivot) l++;
        while (arr[r][0] > pivot) r--;

        if (l <= r)
        {
            swap(&arr[l][0], &arr[r][0]);
            swap(&arr[l++][1], &arr[r--][1]);
        }
    }

    quick_sort(arr, left, r);
    quick_sort(arr, l, right);
}

int main()
{
    int arr[8][2] = {{2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}};
    int i;

    printf("Before Quick Sort:\n");
    for (i = 0; i < 8; i++) printf(" %d %d\n", arr[i][0], arr[i][1]);
    printf("\n");
    quick_sort(arr, 0, 7);
    printf("After Quick Sort:\n");
    for (i = 0; i < 8; i++) printf(" %d %d\n", arr[i][0], arr[i][1]);

    return 0;
}