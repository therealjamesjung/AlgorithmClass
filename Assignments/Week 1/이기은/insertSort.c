//
// Created by KieunLEE on 2019-07-12.
//
#include <stdio.h>
#include <stdlib.h>

int* insertSort(int* arr, int N){
    int key = 0, j;

    for(int i = 1 ; i < N; i++){
        key = arr[i];
        for(j = i - 1 ; j >= 0 && key < arr[j] ; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

    return arr;
}

int main()
{
    int *arr;
    int N;

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int)*N);

    for(int i =0 ;i<N; i++){
        scanf("%d", &arr[i]);
    }

    insertSort(arr, N);

    for(int i = 0;i<N;i++){
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}
