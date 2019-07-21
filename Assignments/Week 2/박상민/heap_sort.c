//
// Created by front on 2019-07-21.
//

#include<stdio.h>
#include<stdlib.h>
void up_heap(int *arr, int i,int N);
void swap(int *arr, int a, int b);
int main() {
    int *arr, n, i,N=1;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int)*(n+1));
    for (i = 1; i < n+1; i++) {
        scanf("%d", &arr[i]);
        up_heap(arr, i,N++);
    }
    for (i = 1; i < n + 1; i++) {
        printf(" %d", arr[i]);
    }
}
void up_heap(int *arr, int i,int N) {
    if (i == 1)
        return;
    if (i == 2) {
        if (i == N) {
            if (arr[2] > arr[1])
                swap(arr,1, 2);
        }
        else {
            if (arr[2] > arr[1])
                swap(arr, 1, 2);
            if (arr[3] > arr[1])
                swap(arr, 1, 3);
            up_heap(arr, i / 2, N);
        }
    }
    else if (i == 3) {
        if (arr[3] > arr[1])
            swap(arr, 1, 3);
        if (arr[2] > arr[1])
            swap(arr, 1, 2);
    }
    else if(i>3){
        if (arr[i / 2] < arr[i])
            swap(arr, i / 2, i);
        if (i % 2 == 0) {
            if (arr[i / 2] < arr[i / 2 * 2 + 1]&&i/2*2+1 != N+1)
                swap(arr, i / 2, i / 2 * 2 + 1);
        }
        if (i % 2 == 1) {
            if (arr[i / 2] < arr[i / 2 * 2]&&i/2*2 != N-1)
                swap(arr, i / 2, i / 2 * 2);
        }
        up_heap(arr, i / 2, N);
    }
}
void swap(int *arr, int a, int b) {
    int tmp = 0;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}