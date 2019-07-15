#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
void Insert(int *a, int N);

int main() {
	int i, j, N, *p, index, *q, *r;

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
	Insert(p, N);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);

	QueryPerformanceCounter(&t1);
	Insert(q, N);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);


	QueryPerformanceCounter(&t1);
	Insert(r, N);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec
	printf("Time by selection sort: %lf ms\n", elapsed_time);



	return 0;
}

void Insert(int *p, int N) {
	int i, j, index;
	for (i = 1; i < N; i++) {
		index = p[i];
		for (j = i - 1; j >= 0; j--) {
			if (p[j] > index) {
				p[j + 1] = p[j];
				continue;
			}
			break;
		}
		p[j + 1] = index;
	}

	
}
