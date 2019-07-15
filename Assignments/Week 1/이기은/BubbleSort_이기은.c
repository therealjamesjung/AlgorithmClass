//
// Created by KieunLEE on 2019-07-12.
//
#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int* arr, int N){
    int tmp;

    for(int i = 0 ; i < N - 1 ; i++){
        for(int j = 0 ; j < N - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    return arr;
}

int main()
{
    int *arr;
    int N;

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int)*N);

    for(int i = 0 ; i < N ; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, N);

    for(int i = 0 ; i < N ; i++){
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}
