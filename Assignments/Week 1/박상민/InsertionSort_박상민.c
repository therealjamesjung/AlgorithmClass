#include<stdio.h>
int main() {
	int *arr, n, i, j, tmp = 0;
	int key = 0;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] >= key) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			else {
				arr[j + 1] = key;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
}