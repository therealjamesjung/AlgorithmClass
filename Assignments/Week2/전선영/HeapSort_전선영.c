#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void downheap(int *arr, int i, int cnt)
{
    if (i == 0)
        return;
    if (i * 2 + 1 <= cnt)
    {
        if (arr[i] > arr[i * 2] || arr[i] > arr[i * 2 + 1])
        {
            if (arr[i * 2] < arr[i * 2 + 1])
                swap(arr + i, arr + (i * 2));
            else
                swap(arr + i, arr + (i * 2) + 1);
        }
    }
    else if (i * 2 <= cnt) {
        if (arr[i] > arr[i * 2]) {
            swap(arr + i, arr + i * 2);
        }
    }
    downheap(arr, --i, cnt);
}
int main()
{
    int n, i, a, *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*(n + 1));
    arr[0] = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        arr[i + 1] = a;
    }
    while (n > 0) {
        downheap(arr, n / 2, n);
        printf("%d\n", arr[1]);
        arr[1] = arr[n];
        arr[n] = 0;
        n--;
    }
}

