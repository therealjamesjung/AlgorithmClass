#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, j, n, min, min_index = 0, tmp;
	int *arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n; i++)
	{
		min = arr[i];
		min_index = i;
		for (j = i; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				min_index = j;
			}
		}
		tmp = arr[i];
		arr[i] = min;
		arr[min_index] = tmp;
	}

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

  free(arr);
}