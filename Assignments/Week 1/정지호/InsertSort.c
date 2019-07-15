#include<stdio.h>

int main()
{
	int N, i, j, tmp;
	int arr[1000], * par;
	scanf("%d", &N);

	for (par = arr; par < arr + N; par++)
		scanf("%d", par);

	for (i = 1; i < N; i++)
	{
		tmp = arr[i];
		for (j = i; j > 0; j--)
		{
			if (tmp > arr[j - 1]) break;
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}

	for (par = arr; par < arr + N; par++)
		printf("%d\n", *par);


}