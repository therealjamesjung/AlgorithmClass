#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main() {
	int N, *arr = NULL;
	int i, j, key, tmp;

	scanf("%d", &N);
	arr = (int *)malloc(N * sizeof(int));
	if (arr == NULL) return -1;
	for (i = 0;i < N;i++)
		scanf("%d", &arr[i]);

	for (i = 1;i < N;i++) {
		key = arr[i];
		for (j = i;j > 0;j--) {
			if (key < arr[j - 1])
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = key;
	}
	for (i = 0;i < N;i++)
		printf("%d\n", arr[i]);

	free(arr);
}