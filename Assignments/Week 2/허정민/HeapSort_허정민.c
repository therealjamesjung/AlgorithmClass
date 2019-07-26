#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void UpHeap(int *arr, int idx) {
    while (idx / 2) {
        if (arr[idx] < arr[idx / 2]) swap(arr + idx, arr + idx / 2);
        else break;
        idx /= 2;
    }
}

void DownHeap(int *arr, int len, int index) {
    if (index * 2 > len) return;
    else if (index * 2 == len) {
        if (arr[index] > arr[index * 2]) {
            swap(arr + index, arr + index * 2);
            DownHeap(arr, len, index * 2);
        }
    }
    else if (arr[index]>arr[index*2]||arr[index]>arr[index*2+1]) {
        if (arr[index * 2] < arr[index * 2 + 1]) {
            swap(arr + index * 2, arr + index);
            DownHeap(arr, len, index * 2);
        }
        else {
            swap(arr + index * 2 + 1, arr + index);
            DownHeap(arr, len, index * 2 + 1);
        }
    }
}

int main() {
    int N, *arr, idx = 0, i;
    scanf("%d", &N);
    arr = (int*)calloc(N + 1, sizeof(int));
    for (i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = N/2; i > 0; i--) {
        DownHeap(arr, N, i);
    }
    idx = N;
    for (i = 1; i <= N; i++) {
        printf("%d\n", arr[1]);
        arr[1] = arr[idx--];
        DownHeap(arr, idx, 1);
    }
    free(arr);
    return 0;
}