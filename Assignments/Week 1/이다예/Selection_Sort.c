#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {
	int N, *arr = NULL;
	int i, j, min, min_index, tmp;

	scanf("%d", &N);
	arr = (int *)malloc(N * sizeof(int));
	if (arr == NULL) return -1;
	for (i = 0;i < N;i++)
		scanf("%d", &arr[i]);

	for (i = 0;i < N - 1;i++) {
		min = arr[i];
		for (j = i;j < N;j++) {
			if (arr[j] <= min) {
				min = arr[j];
				min_index = j;
			}
		}
		tmp = arr[i];
		arr[i] = min;
		arr[min_index] = tmp;
	}
	for (i = 0;i < N;i++)
		printf("%d\n", arr[i]);

	free(arr);
}