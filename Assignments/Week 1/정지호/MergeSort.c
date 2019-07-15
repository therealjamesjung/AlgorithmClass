#include<stdio.h>
#include<stdlib.h>


void Merge_Array(int *arr, int left, int right);
void Divide_Array(int *arr, int left, int right);
int main()
{
	int N;
	int arr[1000], * par = arr;
	scanf("%d", &N);

	for (par = arr; par < arr + N; par++)
		scanf("%d", par);

	Divide_Array(arr, 0, N - 1);

	for (par = arr; par < arr + N; par++)
		printf("%d\n", *par);


}

void Merge_Array(int* arr, int left, int right)
{
	int mid = (left + right) / 2 + 1;
	int center = mid, i;
	int L = left, R = right;
	int size = (right - left + 1);
	int* Arr, Num = 0;
	Arr = (int*)malloc(sizeof(int) * size);

	while (L < mid && center <= R)
	{
		if (arr[L] > arr[center]) Arr[Num++] = arr[center++];
		else Arr[Num++] = arr[L++];
	}
	while (L < mid) Arr[Num++] = arr[L++];
	while (center <= right) Arr[Num++] = arr[center++];
	for (i = 0; i < size; i++) arr[left++] = Arr[i];
	free(Arr);
}
void Divide_Array(int* arr, int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right)
	{
		Divide_Array(arr, left, mid);
		Divide_Array(arr, mid + 1, right);
		Merge_Array(arr, left, right);
	}
}
