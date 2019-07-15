//
// Created by KieunLEE on 2019-07-13.
//
#include <stdio.h>
#include <stdlib.h>


int sort(int* arr, int left, int right){
    int pivot, tmp, length;
    int leftStart = left;
    int rightStart = right;

    pivot = arr[left];
    length = right-left+1;

    while(leftStart<rightStart){
        while(arr[leftStart]<pivot){
            leftStart++;
        }
        while(arr[rightStart]>pivot){
            rightStart--;
        }
        tmp = arr[leftStart];
        arr[leftStart] = arr[rightStart];
        arr[rightStart] = tmp;
    }
    arr[leftStart] = pivot;

    return leftStart;
}

void quickSort(int *arr, int left, int right){
    if(left<right){
        int ipivot = sort(arr, left, right);

        quickSort(arr, left, ipivot-1);
        quickSort(arr, ipivot+1, right);
    }

}

int main()
{
    int N;
    int* arr;

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int)*N);

    for(int i = 0 ; i < N; i++){
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, N-1);

    for(int i = 0 ; i < N ; i++){
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}