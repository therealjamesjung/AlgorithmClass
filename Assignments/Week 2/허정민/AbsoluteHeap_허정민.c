#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int compare(int a, int b) {
    if (abs(a) < abs(b)) return a;
    else if (abs(a) > abs(b)) return b;
    else if (a < b) return a;
    else return b;
}

void UpHeap(int *arr, int idx) {
    while (idx / 2) {
        if (compare(arr[idx],arr[idx/2])==arr[idx]) swap(arr + idx, arr + idx / 2);
        else break;
        idx /= 2;
    }
}

void DownHeap(int *arr, int len, int index) {
    if (index * 2 > len) return;
    else if (index * 2 == len) {
        if (compare(arr[index * 2], arr[index]) == arr[index * 2]) {
            swap(arr + index * 2, arr + index);
            DownHeap(arr, len, index * 2);
        }
    }
    else {
        if (compare(arr[index * 2], arr[index * 2 + 1]) == arr[index * 2]) {
            if (compare(arr[index * 2], arr[index]) == arr[index * 2]) {
                swap(arr + index * 2, arr + index);
                DownHeap(arr, len, index * 2);
            }
        }
        else {
            if (compare(arr[index * 2 + 1], arr[index]) == arr[index * 2 + 1]) {
                swap(arr + index * 2 + 1, arr + index);
                DownHeap(arr, len, index * 2 + 1);
            }
        }
    }
}

int main() {
    int N, *arr, idx = 0, i,input;
    scanf("%d", &N);
    arr = (int*)calloc(N + 1, sizeof(int));
    for (i = 1; i <= N; i++) {
        scanf("%d", &input);
        if (input == 0) {
            if (!idx) printf("0\n");
            else {
                printf("%d\n", arr[1]);
                arr[1] = arr[idx--];
                DownHeap(arr, idx, 1);
            }
        }
        else {
            arr[++idx] = input;
            UpHeap(arr, idx);
        }
    }
    free(arr);
    return 0;
}