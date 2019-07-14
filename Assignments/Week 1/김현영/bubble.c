#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, j, n, tmp;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	 

	free(arr);
}
