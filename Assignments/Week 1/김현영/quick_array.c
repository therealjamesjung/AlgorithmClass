#include<stdio.h>
#include<stdlib.h>

void quick(int* arr, int left, int right);

int main() {
	int i, n, * arr;
	scanf("%d ", &n);
	arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);


	quick(arr, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

}

void quick(int* arr, int left, int right)
{
	int i, temp, pivot, l = left + 1, r = right;
	int size = right - left + 1;

	if (size == 1) return;

	pivot = arr[left];

	while (l < r) {
		if (arr[r] > pivot) r--;
		if (arr[l] <= pivot) l++;
		if (r < l) break;
		if (arr[l] > pivot && arr[r] <= pivot)
		{
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++; r--;
		}
	}

	if ((l == r && (pivot > arr[l])) || (r < l))
	{
		temp = arr[r];
		arr[r] = arr[left];
		arr[left] = temp;
	}
	if (r != left)	{quick(arr, left, r - 1);}
	if (r == l) { quick(arr, r, right); }
	else quick(arr, r + 1, right);

}