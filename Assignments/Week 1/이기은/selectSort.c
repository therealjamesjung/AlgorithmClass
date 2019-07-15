//
// Created by KieunLEE on 2019-07-12.
//
#include <stdio.h>
#include <stdlib.h>

int* selectSort(int* arr, int N){
    int min=0, tmp =0, index =0;

    for(int i = 0 ; i<N;i++){
        min = arr[i];
        index = i;
        for(int j =i ;j<N;j++){
            if(min>arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        tmp=arr[i];
        arr[i] = min;
        arr[index] = tmp;
    }

    return arr;
}

int main()
{
    int *arr;
    int N;

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int)*N);

    for(int i =0 ; i<N;i++){
        scanf("%d", &arr[i]);
    }

    selectSort(arr, N);

    for(int i = 0 ; i< N; i++){
        printf("%d\n", arr[i] );
    }

    free(arr);

    return 0;
}
