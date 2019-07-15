#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, j, k, n,index, tmp;
	int *arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (i = 1; i < n; i++)
	{
		index = i;
		for (j = i-1; j > -1; j--)
		{
			if (arr[index] < arr[j])
			{
				tmp = arr[index];
				arr[index] = arr[j];
				arr[j] = tmp;
				index--;
			}
		}
	}


	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

  free(arr);

}