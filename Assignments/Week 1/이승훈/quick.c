#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void Swap(int *st, int a, int b);
int Pivot_(int *st, int a, int b);
void QuickSort(int *st, int a, int b);

int main() {
	int N, i;
	int *p, *q, *r;

	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsed_time;

	QueryPerformanceFrequency(&frequency);

	scanf("%d", &N);
	p = (int *)malloc(sizeof(int)*N);
	q = (int *)malloc(sizeof(int)*N);
	r = (int *)malloc(sizeof(int)*N);

	srand(time(NULL));

	for (i = 0; i < N; i++) p[i] = rand() % 1000;
	for (i = 0; i < N; i++) q[i] = i;
	for (i = 0; i < N; i++) r[i] = N - i;
	//p[i]=rand()%1000;

	QueryPerformanceCounter(&t1);
	QuickSort(p, 0, N - 1);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);

	QueryPerformanceCounter(&t1);
	QuickSort(q, 0, N - 1);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);

	QueryPerformanceCounter(&t1);
	QuickSort(r, 0, N - 1);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);






	return 0;
}

void Swap(int *st, int a, int b){
	int temp = st[a];
	st[a] = st[b];
	st[b] = temp;
}
int Pivot_(int *st, int a, int b) {
	int pivot = st[a], low = a + 1, high = b;

	while (low <= high) {
		while (pivot >= st[low] && low <= b){ 
			low++;
		}
		while (pivot <= st[high] && high >= (a + 1)) {
			high--;
		}
		if (low <= high) {
			Swap(st, low, high);
		}
	}
	Swap(st, a, high);
	return high;
}

void QuickSort(int *st, int a, int b) {
	int pivot;
	if (a <= b) {
		pivot = Pivot_(st, a, b);
		QuickSort(st, a, pivot - 1);
		QuickSort(st, pivot + 1, b);
	}
}