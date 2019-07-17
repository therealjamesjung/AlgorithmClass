#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
void Q_sort(int *ar, int N, int point);
int get_gab(int a, int b);
int setPIVOT(int *ar, int N);
void divi(int *ar, int N);
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
		*(arr1 + i) = rand();
	}
	//insertion_sort(arr1, n);  //<< 정렬된 데이터 삽입시 주석처리 제거
	//reverse_array(arr1, 0, n - 1); //<< 역정렬 데이터 삽입시 주석처리 제거

	QueryPerformanceCounter(&t1);
	divi(arr1, N);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec

	printf("Time by quick sort: %lf ms\n", elapsed_time);
	return 0;
}
void divi(int *ar, int N) {
	int point;
	int i;
	point = setPIVOT(ar, N);
	if (N <= 0) return;
	if (point <= 1 && N - point - 1 <= 1) {
		Q_sort(ar, N, point);
		return;
	}
	Q_sort(ar, N, point);
	point = setPIVOT(ar, N);
	divi(ar, point);
	divi(ar + point + 1, N - point - 1);

}
void Q_sort(int *ar, int N, int point) {
	int *sub;
	int i, j = 0;
	int pivot;

	sub = (int*)malloc(sizeof(int)*N);
	pivot = ar[point];

	for (i = 0; i < N; i++) {
		if (ar[i] < pivot && i != point) {
			sub[j] = ar[i];
			j++;
		}
	}
	for (i = 0; i < N; i++) {
		if (ar[i] == pivot && i != point) {
			sub[j] = ar[i];
			j++;
		}
	}
	sub[j] = pivot;
	j++;
	for (i = 0; i < N; i++) {
		if (ar[i] > pivot && i != point) {
			sub[j] = ar[i];
			j++;
		}
	}
	for (i = 0; i < N; i++) {
		ar[i] = sub[i];
	}
}
int get_gab(int a, int b) {
	if (a - b >= 0) return a - b;
	else return b - a;
}
int setPIVOT(int *ar, int N) {
	int i;
	int num = 0;
	int gabdex;
	int gab;
	int avg;
	if (N <= 0) return;
	for (i = 0; i < N; i++) {
		num += ar[i];
	}
	avg = num / N * 1.0;
	gab = get_gab(ar[0], avg);
	gabdex = 0;
	for (i = 0; i < N; i++) {
		if (gab >= get_gab(ar[i], avg)) {
			gab = get_gab(ar[i], avg);
			gabdex = i;
		}
	}
	return gabdex;
}