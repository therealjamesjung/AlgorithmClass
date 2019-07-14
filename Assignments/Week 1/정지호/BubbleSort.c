#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b);
int main() {

	int n, i, j;
	int *arr, * par;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (par = arr; par < arr + n; par++)
		scanf("%d", par);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
				swap((arr + j), (arr + j + 1));
		}
	}

	for (par = arr; par < arr + n; par++)
		printf("%d\n", *par);

	return 0;

}
void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
