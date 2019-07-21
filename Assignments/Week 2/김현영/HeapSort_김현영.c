#include<stdio.h>
#include<stdlib.h>

void Swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void BuildHeap(int* arr, int self, int n)
{
	int left = self * 2, right = left + 1;
	if (left > n) return;

	if (right <= n) //right o
	{
		if (arr[self] < arr[left] || arr[self] < arr[right])
		{
			if (arr[left] > arr[right])
			{
				Swap(&arr[self], &arr[left]);
				BuildHeap(arr, left, n);
			}
			else
			{
				Swap(&arr[self], &arr[right]);
				BuildHeap(arr, right, n);
			}
		}
	}
	else //only left
		if (arr[self] < arr[left]) Swap(&arr[self], &arr[left]);
}


int main()
{
	int i, n;
	int* arr;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * (n + 1));

	for (i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	for (i = n / 2; i > 0; i--)
		BuildHeap(arr, i, n);

	i = n;
	while (1)
	{
		Swap(&arr[1], &arr[i]);
		i--;
		BuildHeap(arr, 1, i);
		if (i <= 1) break;
	}

	for (i = 1; i <= n; i++)
		printf("%d ", arr[i]);


}