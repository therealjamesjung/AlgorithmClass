#include<stdio.h>
#include<math.h>

void DownHeap(int* arr, int Current_Index, int Last_Index);
void Swap(int* A, int* B);
int main()
{
	int* arr;
	int N, data, i, Idx;

	scanf("%d", &N);
	Idx = N;

	arr = (int*)malloc(sizeof(int) * (N + 1));

	for (i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (i = N / 2; i >= 1; i--)
		DownHeap(arr, i, N);
		
	for (i = 1; i <= N; i++)
	{
		printf("¹è¿­ °ª : %d\n", arr[1]);
		Swap(&arr[1], &arr[Idx--]);
		arr = (int*)realloc(arr, sizeof(int) * (Idx + 1));
		DownHeap(arr, 1, Idx);
	}


}
void DownHeap(int* arr, int Current_Index, int Last_Index)
{
	int Left, Right;
	Left = Current_Index * 2;
	Right = Left + 1;

	if (Left > Last_Index)
		return;
	if (Left == Last_Index)
	{
		if (arr[Left] < arr[Current_Index])
		{
			Swap(&arr[Left], &arr[Current_Index]);
			DownHeap(arr, Left, Last_Index);
			return;
		}
		else
			return;
	}
	else if (Left < Last_Index)
	{
		if (arr[Left] < arr[Right])
		{
			if (arr[Left] < arr[Current_Index])
			{
				Swap(&arr[Left], &arr[Current_Index]);
				DownHeap(arr, Left, Last_Index);
			}
		}
		else if (arr[Right] < arr[Left])
		{
			if (arr[Right] < arr[Current_Index])
			{
				Swap(&arr[Right], &arr[Current_Index]);
				DownHeap(arr, Right, Last_Index);
			}
		}
	}
}
void Swap(int* A, int* B)
{
	int tmp;
	tmp = *A;
	*A = *B;
	*B = tmp;
}