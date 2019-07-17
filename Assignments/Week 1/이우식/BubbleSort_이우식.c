#pragma warning (disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
int main() {
	int *arr1;
	int N;
	int tmp;
	int i, j;
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsed_time;
	QueryPerformanceFrequency(&frequency);
	srand(time(NULL));
	scanf("%d", &N);
	arr1 = (int *)malloc(sizeof(int)*N);
	for (i = 0; i < N; i++) {
		*(arr1 + i) = N - i;
	}
	//insertion_sort(arr1, n);  //<< 정렬된 데이터 삽입시 주석처리 제거
	//reverse_array(arr1, 0, n - 1); //<< 역정렬 데이터 삽입시 주석처리 제거

	QueryPerformanceCounter(&t1);
	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (arr1[i] < arr1[j]) {
				tmp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = tmp;
			}
		}
	}
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec

	printf("Time by selection sort: %lf ms\n", elapsed_time);
	return 0;
}