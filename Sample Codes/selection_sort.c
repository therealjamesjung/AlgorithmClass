#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *arr, int n)
{
    int *p, *q;
    int max, tmp, *p_max = arr;
    int flag;

    for (p = arr + n - 1; p >= arr; p--)
    {
        max = *p;
        flag = 0;
        for (q = p; q >= arr; q--)
        {
            if (*q > max)
            {
                max = *q;
                p_max = q;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            tmp = *p;
            *p = *p_max;
            *p_max = tmp;
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

    selection_sort(arr, n);

    for (i = 0; i < n; i++) printf(" %d", arr[i]);

    free(arr);

    return 0;
}