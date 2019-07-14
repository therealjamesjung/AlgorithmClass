#include<stdio.h>
#include<stdlib.h>

void Divide(int *arr, int front, int end);
void merge_sort(int *arr, int front, int end);

int main() {
	int i, j, n, tmp;
	int *arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	Divide(arr, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	free(arr);
}


void Divide(int *arr, int first, int end)
{
	int mid;
	mid = (end + first) / 2;
	if (end - first == 0) return;

	Divide(arr, first, mid);
	Divide(arr, mid + 1, end);
	merge_sort(arr, first, end);
}
void merge_sort(int *arr, int first, int end)
{
	int i = 0, size, mid, f, m, *tmp;
	size = end - first + 1;
	mid = (end + first) / 2 + 1;
	f = first;
	m = mid;
	tmp = (int*)malloc(sizeof(int)*size);

	while (f < mid && m <= end)
	{
		if (arr[f] > arr[m])
			tmp[i++] = arr[m++];
		else
			tmp[i++] = arr[f++];
	}

	while (f < mid)
		tmp[i++] = arr[f++];
	while (m <= end)
		tmp[i++] = arr[m++];

	for (i = 0; i < size; i++)
		arr[first++] = tmp[i];

	free(tmp);
}
