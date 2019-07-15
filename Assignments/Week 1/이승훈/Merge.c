#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void MergeSort(int *st, int p, int r);
void Merge(int *st, int p, int q, int r);

int main() {
	int i, N, *p, *q, *r;

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

	QueryPerformanceCounter(&t1);
	MergeSort(p, 0, N - 1);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);


	QueryPerformanceCounter(&t1);
	MergeSort(q, 0, N - 1);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);

	QueryPerformanceCounter(&t1);
	MergeSort(r, 0, N - 1);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);

	return 0;
}

void MergeSort(int *st, int p, int r) {
	int q;
	if (p < r) {
		q = (p + r) / 2;
		MergeSort(st, p, q);
		MergeSort(st, q + 1, r);
		Merge(st, p, q, r);
	}
}
void Merge(int *st, int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	int *tmp = (int *)malloc(sizeof(int)*r+1);
	while (i <= q && j <= r) {
		if (st[i] <= st[j]) tmp[k++] = st[i++];
		else tmp[k++] = st[j++];
	}
	while (i <= q) tmp[k++] = st[i++];
	while (j <= r) tmp[k++] = st[j++];
	for (int a = p; a <= r; a++) st[a] = tmp[a];
	free(tmp);
}
