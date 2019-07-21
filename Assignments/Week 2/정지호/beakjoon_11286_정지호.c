#include<stdio.h>
#include<stdlib.h>

typedef struct Heap
{
	int* arr, * Arr;
	int Index;
	int Min;
}Heap;
void UpHeap(Heap* H, int data);
void DownHeap(Heap* H);
void Swap2(Heap* H, int L, int R);
void Realloc(Heap* H);
int main()
{
	int N, i, j;
	int data, Min;
	Heap H;

	scanf("%d", &N);
	H.arr = (int*)malloc(sizeof(int));
	H.Arr = (int*)malloc(sizeof(int));
	H.Index = 0;
	H.Min = 1;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &data);
		if (data == 0)
		{
			if (H.Index == 0)
				printf("0\n");
			else
			{
				H.Min = 1;
				printf("%d\n", H.arr[H.Min]);
				Swap2(&H, 1, H.Index);
				H.Index--;
				Realloc(&H);
				DownHeap(&H);
			}
		}
		else
		{
			H.Index++;
			Realloc(&H);
			H.arr[H.Index] = data;
			H.Arr[H.Index] = abs(data);
			UpHeap(&H, H.Index);
		}
	}
	free(H.arr);
	free(H.Arr);
}
void UpHeap(Heap* H, int Lastindex)
{
	int index = Lastindex;
	if (index / 2 <= 0 || H->Arr[index / 2] < H->Arr[index])
		return;
	else if (H->Arr[index / 2] > H->Arr[index])
		Swap2(H, index, index / 2);
	else if (H->Arr[index / 2] == H->Arr[index])
	{
		if (H->arr[index / 2] > H->arr[index])
			Swap2(H, index, index / 2);
		else
			return;
	}
	index /= 2;
	UpHeap(H, index);
}
void DownHeap(Heap * H)
{
	int Left, Right;
	int Compare;
	Left = H->Min * 2;
	Right = H->Min * 2 + 1;
	if (H->Index < Left)
		return;
	if (H->Index != Left)
	{
		if (H->Arr[Left] == H->Arr[Right])
			Compare = H->arr[Left] < H->arr[Right] ? Left : Right;
		else
			Compare = H->Arr[Left] < H->Arr[Right] ? Left : Right;
	}
	if (H->Index == Left)
	{
		if (H->Arr[Left] < H->Arr[H->Min])
			Swap2(H, H->Min, Left);
		else if (H->Arr[Left] == H->Arr[H->Min])
		{
			if (H->arr[Left] < H->arr[H->Min])
				Swap2(H, H->Min, Left);
		}

	}
	else if (H->Arr[Compare] < H->Arr[H->Min])
	{
		Swap2(H, Compare, H->Min);
		DownHeap(H);
	}
	else if (H->Arr[Compare] == H->Arr[H->Min])
	{
		if (H->arr[Compare] < H->arr[H->Min])
		{
			Swap2(H, Compare, H->Min);
			DownHeap(H);
		}
	}
}
void Swap2(Heap * H, int L, int R)
{
	int tmp, Tmp;
	tmp = H->arr[L];
	H->arr[L] = H->arr[R];
	H->arr[R] = tmp;
	Tmp = H->Arr[L];
	H->Arr[L] = H->Arr[R];
	H->Arr[R] = Tmp;
	H->Min = L;
}
void Realloc(Heap * H)
{
	H->arr = (int*)realloc(H->arr, sizeof(int) * (H->Index + 1));
	H->Arr = (int*)realloc(H->Arr, sizeof(int) * (H->Index + 1));
}