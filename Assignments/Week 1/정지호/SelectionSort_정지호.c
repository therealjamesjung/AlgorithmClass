#include<stdio.h>
void swap(int* a, int* b);
int main() {

	int n, i, j, max, tmp;
	int arr[1000], * par;
	scanf("%d", &n);

	for (par = arr; par < arr + n; par++)
		scanf("%d", par);
	par = arr;
	for (i = 0; i < n; i++)
	{
		max = i;
		for (j = i; j < n; j++)
		{
			if (arr[max] > arr[j])
				max = j;
		}
		tmp = arr[i];
		arr[i] = arr[max];
		arr[max] = tmp;
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