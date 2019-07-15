//
// Created by KieunLEE on 2019-07-13.
//
#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int right){
    int* tmp;
    int mid = (left+right)/2 + 1;
    int len = (right - left + 1);
    int i = 0, l = left, m = mid ;

    tmp = (int*)malloc(sizeof(int)*len);

    while(l<mid && m<=right){
        if (arr[l] < arr[m]) tmp[i++] = arr[l++];
        else tmp[i++] = arr[m++];
    }

    while (l < mid) {
        tmp[i++] = arr[l++];
    }

    while (m <= right) {
        tmp[i++] = arr[m++];
    }

    for (i = 0 ; i < len; i++) {
        arr[left++] = tmp[i];
    }

    free(tmp);
}

void mergeSort(int* arr, int left, int right){
    int mid = (left+right)/2;

    if(right - left < 1) return;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, right);

}

int main()
{
    int N, *arr;

    scanf("%d", &N);

    arr = (int*)malloc(sizeof(int)*N);

    for(int i = 0 ; i < N ;i++){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, N-1);

    for(int i = 0 ; i < N ; i++){
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;
}