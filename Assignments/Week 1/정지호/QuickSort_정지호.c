#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int* a, int* b);
void Divide_Array(int *arr,int left, int right);
int main()
{
	int N;
	int* arr, * par;

	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int) * N);

	for (par = arr; par < arr + N; par++)
		scanf("%d", par);
	Divide_Array(arr, 0, N - 1);
	for (par = arr; par < arr + N; par++)
		printf("%d\n", *par);


}
void Divide_Array(int* arr, int left, int right)
{
    int Pivot = arr[(left + right) / 2];
    int L = left;
    int R = right;

    while (L <= R)
    {
        while (arr[L] < Pivot)
            L++;
        while (arr[R] > Pivot)
            R--;
        if (L <= R)
        {
            if (L != R)
                swap(&arr[L], &arr[R]);
            L++, R--;
        }

    }
    if (left < R)
        Divide_Array(arr, left, R);
    if (L < right)
        Divide_Array(arr, L, right);


}
void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
