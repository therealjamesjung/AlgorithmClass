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
void upheap(int *arr, int cnt)
{
    int i = cnt;
    if (cnt == 1)
        return;
    if (abs(arr[i]) < abs(arr[i / 2]))
    {
        swap(arr + i, arr + (i / 2));
        upheap(arr, cnt / 2);
    }
    else if (abs(arr[i]) == abs(arr[i / 2]))
    {
        if (arr[i] < arr[i / 2])
        {
            swap(arr + i, arr + (i / 2));
            upheap(arr, cnt / 2);
        }
    }
}
void downheap(int *arr, int i, int cnt)
{
    if (i > cnt)
        return;
    if (i * 2 + 1 <= cnt)
    {
        if (abs(arr[i]) > abs(arr[i * 2]) || abs(arr[i]) > abs(arr[i * 2 + 1])) {
            if (abs(arr[i * 2]) < abs(arr[i * 2 + 1])) {
                swap(arr + i, arr + (i * 2));
                downheap(arr, i * 2, cnt);
            }
            else if (abs(arr[i * 2]) == abs(arr[i * 2 + 1])) {
                if (arr[i * 2] < arr[i * 2 + 1]) {
                    swap(arr + i, arr + (i * 2));
                    downheap(arr, i * 2, cnt);
                }
                else {
                    swap(arr + i, arr + (i * 2) + 1);
                    downheap(arr, i * 2 + 1, cnt);
                }
            }
            else {
                swap(arr + i, arr + (i * 2) + 1);
                downheap(arr, i * 2 + 1, cnt);
            }
        }
        else if (abs(arr[i]) == abs(arr[i * 2]) || abs(arr[i]) == abs(arr[i * 2 + 1]))
        {
            if (arr[i * 2] < arr[i * 2 + 1]) {
                if (arr[i] > arr[i * 2])
                {
                    swap(arr + i, arr + (i * 2));
                    downheap(arr, i * 2, cnt);
                }
            }
            else {
                if (arr[i] > arr[i * 2])
                {
                    swap(arr + i, arr + (i * 2) + 1);
                    downheap(arr, i * 2 + 1, cnt);
                }
            }
        }
    }
    if (i * 2 <= cnt) {
        if (abs(arr[i]) > abs(arr[i * 2])) {
            swap(arr + i, arr + i * 2);
            downheap(arr, i * 2, cnt);
        }
        else if (abs(arr[i]) == abs(arr[i * 2])) {
            if (arr[i] > arr[i * 2]) {
                swap(arr + i, arr + i * 2);
                downheap(arr, i * 2, cnt);
            }
        }
    }
}
int main()
{
    int n, i, a, *arr, cnt = 0;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int)*n);
    arr[0] = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (a != 0)
        {
            cnt++;
            arr[cnt] = a;
            upheap(arr, cnt);
        }
        else
        {
            if (cnt == 0)
                printf("0\n");
            else
            {
                printf("%d\n", arr[1]);
                arr[1] = arr[cnt];
                arr[cnt] = 0;
                --cnt;
                downheap(arr, 1, cnt);
            }
        }
    }
}