#include<stdio.h>
int main() {
	int *arr, n, i, j, tmp = 0;
	int min = 0;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < n - 1; i++) {
		min = arr[i];
		for (j = i; j < n; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		printf("%d\n", arr[min]);
		tmp = arr[min];
		arr[min] = arr[i];
		arr[i] = tmp;
	}
	for (i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
}