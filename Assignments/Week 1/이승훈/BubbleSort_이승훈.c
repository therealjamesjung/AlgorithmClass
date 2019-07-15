#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void swap(int *a, int *b);


int main() {
	int i, j, N, *p, *q, *r;

	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsed_time;

	QueryPerformanceFrequency(&frequency);

	scanf("%d", &N);
	p = (int *)malloc(sizeof(int)*N);
	q = (int *)malloc(sizeof(int)*N);
	r = (int *)malloc(sizeof(int)*N);
	for (i = 0; i < N; i++) p[i] = rand() % 1000;
	for (i = 0; i < N; i++) q[i] = i;
	for (i = 0; i < N; i++) r[i] = N - i;

	srand(time(NULL));
	QueryPerformanceCounter(&t1);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (p[j] > p[j + 1]) swap(&p[j], &p[j + 1]);
		}
	}
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);

	QueryPerformanceCounter(&t1);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (q[j] > q[j + 1]) swap(&q[j], &q[j + 1]);
		}
	}
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);

	QueryPerformanceCounter(&t1);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N - i - 1; j++) {
			if (r[j] > r[j + 1]) swap(&r[j], &r[j + 1]);
		}
	}
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);





	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}