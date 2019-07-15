#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
LARGE_INTEGER Frequency;
LARGE_INTEGER BeginTime;
LARGE_INTEGER Endtime;
int *make_list(int n)
{
    int a, i, *arr;
    arr = (int*)malloc(sizeof(int)*n);

    srand(1);
    for (i = 0; i < n; i++)
    {
        arr[i]= rand() % 2000 - 1000;
    }
    return arr;
}
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void insert_sort(int *arr,int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        j = i;
        while (arr[j - 1] > arr[j] && j >= 0)
        {
            swap(arr + j - 1, arr + j);
            j--;
        }
    }
}
void Print(int *arr,int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}
int main()
{
    int n, *arr;
    QueryPerformanceFrequency(&Frequency);

    scanf("%d", &n);
    arr = make_list(n);

    QueryPerformanceCounter(&BeginTime);

    insert_sort(arr,n);

    QueryPerformanceCounter(&Endtime);

    __int64 elapsed = Endtime.QuadPart - BeginTime.QuadPart;
    double duringtime = (double)elapsed / (double)Frequency.QuadPart;

    printf("%f\n", duringtime);

    free(arr);

}