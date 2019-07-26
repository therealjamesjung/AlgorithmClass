#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void UP(int *heap, int index) {
	int tmp = 0;
	if (index == 1 || heap[index / 2] < heap[index]) return;
	else {
		tmp = heap[index];
		heap[index] = heap[index / 2];
		heap[index / 2] = tmp;
		UP(heap, index / 2);
	}
}
void DOWN(int *heap, int index, int N) {
	int tmp = 0;
	if (index * 2 > N) return;
	else if (index * 2 < N) {
		if (heap[index * 2] < heap[index * 2 + 1]) {
			if (heap[index] > heap[index * 2]) {
				tmp = heap[index];
				heap[index] = heap[index * 2];
				heap[index * 2] = tmp;
				DOWN(heap, index * 2, N);
			}
			else return;
		}
		else {
			if (heap[index] > heap[index * 2 + 1]) {
				tmp = heap[index];
				heap[index] = heap[index * 2 + 1];
				heap[index * 2 + 1] = tmp;
				DOWN(heap, index * 2 + 1, N);
			}
			else return;
		}
	}
	else {
		if (heap[index] > heap[index * 2]) {
			tmp = heap[index];
			heap[index] = heap[index * 2];
			heap[index * 2] = tmp;
			DOWN(heap, index * 2, N);
		}
		else return;
	}
}
void push(int *heap, int data, int N) {
	heap[N] = data;
	UP(heap, N);
}
int pop(int *heap, int N) {
	int tmp = heap[1];
	heap[1] = heap[N];
	heap[N] = NULL;
	if (N != 1) DOWN(heap, 1, N - 1);

	return tmp;
}
int main() {
	int *heap;
	int N;
	int i;
	int data;
	scanf("%d", &N);
	heap = (int*)malloc(sizeof(int)*(N + 1));
	for (i = 1; i <= N; i++) {
		scanf("%d", &data);
		push(heap, data, i);
	}
	for (i = 0; i < N; i++) {
		printf("%d\n", pop(heap, N - i));
	}
	return 0;
}