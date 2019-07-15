#include<stdio.h>
void combine(int *arr, int left, int right) {
	int mid = (right + left) / 2 + 1;
	int i = 0, *tmp, n = right - left + 1;
	int l = left, r = right, m = mid;
	tmp = (int*)malloc(sizeof(int)*n);
	while (l < mid && m <= right) {
		if (arr[l] > arr[m])tmp[i++] = arr[m++];
		else tmp[i++] = arr[l++];
	}
	while (l < mid) tmp[i++] = arr[l++];
	while (m <= right) tmp[i++] = arr[m++];
	for (i = 0; i < n; i++) arr[left++] = tmp[i];
	free(tmp);
}
void merge(int *arr, int left, int right) {
	int mid = (right + left) / 2;
	if (right - left < 1)return;
	merge(arr, left, mid);
	merge(arr, mid + 1, right);
	combine(arr, left, right);
}
int main() {
	int *arr, i, n;
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	merge(arr, 0, n - 1);
	for (i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	free(arr);
}