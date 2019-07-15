#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {
	int N, *arr = NULL;
	int i, j, tmp;

	scanf("%d", &N);
	arr = (int *)malloc(N * sizeof(int));
	if (arr == NULL) return -1;
	for (i = 0;i < N;i++)
		scanf("%d", &arr[i]);

	for (i = 0;i < N;i++) {
		for (j = 0;j < N - i - 1;j++)
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
	}
	for (i = 0;i < N;i++)
		printf("%d\n", arr[i]);

	free(arr);
}