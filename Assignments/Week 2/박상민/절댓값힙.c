//
// Created by front on 2019-07-21.
//

//
// Created by front on 2019-07-21.
//

#include<stdio.h>
#include<stdlib.h>
void up_heap(int *arr, int i);
void swap(int *arr, int a, int b);
void heap_down(int *arr, int i, int n);
int main() {
    int *arr, n, i, input = 0, N = 1;
    scanf("%d", &n);
    arr = (int*)malloc(sizeof(int)*(n + 1));

    for (i = 1; i < n + 1; i++) {
        scanf("%d", &input);
        if (input != 0) {
            arr[N++] = input;
            up_heap(arr, N - 1);
        }
        else if (input == 0) {//arr배열이 arr[10]까지 있다면 n은 11
            if (N < 2)
                printf("0\n");
            else {
                heap_down(arr, 1, N - 1);
                N--;
            }
        }
    }
}
void heap_down(int *arr, int i, int n) {//arr배열이 arr[10]까지 있으면 n은 10
    if (n == 1) {
        printf("%d\n", arr[1]);
        return;
    }
    if (i > n - 1)  //base
        return;
    if (i == 1) {
        if (n == 2) {
            printf("%d\n", arr[1]);
            arr[1] = arr[2];
            return;
        }
        else if (n == 3) {
            printf("%d\n", arr[1]);
            arr[1] = arr[n];
            if (abs(arr[1]) > abs(arr[2]))
                swap(arr, 1, 2);
            else if (abs(arr[1]) == abs(arr[2])) {
                if (arr[1] > arr[2])
                    swap(arr, 1, 2);
            }
            return;
        }
        else {
            printf("%d\n", arr[1]);//뽑아 냈음
            arr[1] = arr[n];
            if (abs(arr[1]) > abs(arr[2])) {
                swap(arr, 1, 2);
                heap_down(arr, 2, n);
            }
            else if (abs(arr[1]) == abs(arr[2])) {
                if (arr[1] > arr[2])
                    swap(arr, 1, 2);
                heap_down(arr, 2, n);
            }

            if (abs(arr[1]) > abs(arr[3])) {
                swap(arr, 1, 3);
                heap_down(arr, 3, n);
            }
            else if (abs(arr[1]) == abs(arr[3])) {
                if (arr[1] > arr[3])
                    swap(arr, 1, 3);
                heap_down(arr, 3, n);
            }
        }
    }
    else {
        if (abs(arr[i]) > abs(arr[i * 2])) {//왼쪽
            swap(arr, i, i * 2);
            heap_down(arr, i * 2, n);
        }
        else if (abs(arr[i]) == abs(arr[i * 2])) {
            if (arr[i] > arr[i * 2])
                swap(arr, i, i * 2);
            heap_down(arr, i * 2, n);
        }

        if (abs(arr[i]) > abs(arr[i * 2 + 1])) {//오른쪽
            swap(arr, i, i * 2 + 1);
            heap_down(arr, i * 2 + 1, n);
        }
        else if (abs(arr[i]) == abs(arr[i * 2 + 1])) {
            if (arr[i] > arr[i * 2 + 1])
                swap(arr, i, i * 2 + 1);
            heap_down(arr, i * 2 + 1, n);
        }
    }
}
void up_heap(int *arr, int i) {
    if (i == 1) //재귀 함수 끝내는 조건
        return;
    else if (i == 2) {
        if (abs(arr[1]) > abs(arr[2]))
            swap(arr, 1, 2);
        else if (abs(arr[1]) == abs(arr[2])) {
            if (arr[1] > arr[2])
                swap(arr, 1, 2);
        }

        if (abs(arr[1]) > abs(arr[3]))
            swap(arr, 1, 3);
        else if (abs(arr[1] == abs(arr[3]))) {
            if (arr[1] > arr[3])
                swap(arr, 1, 3);
        }
        up_heap(arr, 1);
    }
    else if (i == 3) {
        if (abs(arr[1]) > abs(arr[3]))
            swap(arr, 1, 3);
        else if (abs(arr[1] == abs(arr[3]))) {
            if (arr[1] > arr[3])
                swap(arr, 1, 3);
        }

        if (abs(arr[1]) > abs(arr[2]))
            swap(arr, 1, 2);
        else if (abs(arr[1] == abs(arr[2]))) {
            if (arr[1] > arr[2])
                swap(arr, 1, 2);
        }
        up_heap(arr, 1);
    }
    else {
        if (abs(arr[i]) < abs(arr[i / 2])) {     //   i/2=부모 노드
            swap(arr, i, i / 2);
            up_heap(arr, i / 2);
        }
        else if (abs(arr[i]) == abs(arr[i / 2])) {
            if (arr[i] < arr[i / 2])
                swap(arr, i, i / 2);
            up_heap(arr, i / 2);
        }
        if (i % 2 == 1) {
            if (abs(arr[i / 2] < abs(arr[i / 2 * 2]))) {
                swap(arr, i / 2 * 2, i / 2);
                up_heap(arr, i / 2);
            }
            else if (abs(arr[i / 2]) == abs(arr[i / 2 * 2])) {
                if (arr[i / 2] > arr[i / 2 * 2])
                    swap(arr, i / 2, i / 2 * 2);
                up_heap(arr, i / 2);
            }
        }
        else if (i % 2 == 0) {
            if (abs(arr[i / 2] < abs(arr[i / 2 * 2+1]))) {
                swap(arr, i / 2 * 2, i / 2);
                up_heap(arr, i / 2);
            }
            else if (abs(arr[i / 2]) == abs(arr[i / 2 * 2 + 1])) {
                if (arr[i / 2] > arr[i / 2 * 2 + 1])
                    swap(arr, i / 2, i / 2 * 2 + 1);
                up_heap(arr, i / 2);
            }
        }
    }
}
void swap(int *arr, int a, int b) {
    int tmp = 0;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}