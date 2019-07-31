#include <stdio.h>
#include <stdlib.h>

void merge(int arr[8][2], int left, int right)
{
    int tmp[8][2];
    int n = (right - left + 1);
    int mid = (left + right) / 2 + 1;
    int i = 0, l = left, m = mid;

    while (l < mid && m <= right)
    {
        if (arr[l][0] > arr[m][0])
        {
            tmp[i][0] = arr[m][0];
            tmp[i++][1] = arr[m++][1];
        }
        else
        {
            tmp[i][0] = arr[l][0];
            tmp[i++][1] = arr[l++][1];
        }
    }

    while (l < mid)
    {
        tmp[i][0] = arr[l][0];
        tmp[i++][1] = arr[l++][1];
    }

    while (m <= right)
    {
        tmp[i][0]= arr[m][0];
        tmp[i++][1] = arr[m++][1];
    }

    for (i = 0; i < n; i++)
    {
        arr[left][0] = tmp[i][0];
        arr[left++][1] = tmp[i][1];
    }
}

void merge_sort(int arr[8][2], int left, int right)
{
    int mid = (left + right) / 2;
    if (right - left < 1) return;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);

    merge(arr, left, right);
}

int main()
{
    int arr[8][2] = {{2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}};
    int i;

    merge_sort(arr, 0, 7);
    for (i = 0; i < 8; i++) printf(" %d %d\n", arr[i][0], arr[i][1]);

    return 0;
}