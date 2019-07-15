#include<stdio.h>
void swap(int *arr, int i, int j) {
	int tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void print_arr(int *arr, int n) {
	int i = 0;
	for (i = 0; i<n; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}
int quick_sort(int *arr, int left, int right) {
	int low = left, high = right;
	int pivot = arr[left];
	while (low < high) {
		while (low <= right && arr[low]<pivot) low++;
		while (high >= left && arr[high] > pivot) high--;
		if (low <= high)swap(arr, low, high);
	}
	swap(arr, low, high);
	return high;
}
void quick(int *arr, int left, int right) {
	int n = right - left + 1;
	if (right > left) {
		int a = quick_sort(arr, left, right);
		quick(arr, left, a - 1);
		quick(arr, a + 1, right);
	}
}
int main() {
	int *arr, n, i;
	scanf("%d", &n); arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	quick(arr, 0, n - 1);
	for (i = 0; i < n; i++) printf(" %d", arr[i]);
	free(arr);
}