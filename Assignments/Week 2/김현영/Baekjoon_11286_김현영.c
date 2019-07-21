#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void UpHeap(int* arr, int n)
{
	if (n <= 1) return;

	if (abs(arr[n]) < abs(arr[n / 2]))
		Swap(&arr[n], &arr[n / 2]);

	else if (abs(arr[n]) == abs(arr[n / 2]))
	{
		if (arr[n] < arr[n / 2])
			Swap(&arr[n], &arr[n / 2]);
	}
	UpHeap(arr, n / 2);
}

void Delete(int* arr, int* n)
{
	if (*n < 1)
	{
		printf("0\n");
		return;
	}
	else
	{
		printf("%d\n", arr[1]);
		Swap(&arr[1], &arr[*n]);
		arr[*n] = NULL;
		(*n)--;
	}
}

void DownHeap(int* arr, int self, int n)
{

	int left = self * 2, right = left + 1;
	
	if (left > n) return;

	if (right <= n) //right o
	{
		if (abs(arr[self]) > abs(arr[left]) || abs(arr[self]) > abs(arr[right]))
		{
			if (abs(arr[left]) < abs(arr[right]))
			{
				Swap(&arr[self], &arr[left]);
				DownHeap(arr, left, n);
			}
			else if (abs(arr[left]) == abs(arr[right]))
			{
				if (arr[left] < arr[right])
				{
					Swap(&arr[self], &arr[left]);
					DownHeap(arr, left, n);
				}
				else
				{
					Swap(&arr[self], &arr[right]);
					DownHeap(arr, right, n);
				}
			}
			else
			{
				Swap(&arr[self], &arr[right]);
				DownHeap(arr, right, n);
			}
		}
		else if (abs(arr[self]) == abs(arr[left]) || abs(arr[self]) == abs(arr[right]))
		{
			if (arr[self] > arr[left])
			{
				Swap(&arr[self], &arr[left]);
				DownHeap(arr, left, n);
			}
			else if (arr[self] > arr[right])
			{
				Swap(&arr[self], &arr[right]);
				DownHeap(arr, right, n);
			}
			else
				return;
		}
	}
	else  //only left
	{
		if (abs(arr[self]) > abs(arr[left]))
			Swap(&arr[self], &arr[left]);
		else if (abs(arr[self]) == abs(arr[left]))
		{
			if (arr[self] > arr[left])
				Swap(&arr[self], &arr[left]);
		}
	}
}


int main()
{
	int i, n, size = 0, data;
	int* arr;

	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int) * n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &data);
		if (data != 0)
		{
			size++;
			arr[size] = data;
			UpHeap(arr, size);
		}
		else
		{
			Delete(arr, &size);
			DownHeap(arr,1,size);
		}
	}

	return 0;
}