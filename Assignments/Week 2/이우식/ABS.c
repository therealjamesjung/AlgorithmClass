#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int reset(int a) {
	if (a >= 0)return a;
	else return -a;
}
int vs(int a, int b) {
	if (reset(a) < reset(b)) return a;
	else if (reset(a) > reset(b)) return b;
	else {
		if (a < b) return a;
		else return b;
	}
}
void UP(int *heap, int index) {
	int tmp = 0;
	if (index == 1 || vs(heap[index / 2], heap[index]) == heap[index / 2]) return;
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
		if (vs(heap[index * 2], heap[index * 2 + 1]) == heap[index * 2]) {
			if (vs(heap[index], heap[index * 2]) == heap[index * 2]) {
				tmp = heap[index];
				heap[index] = heap[index * 2];
				heap[index * 2] = tmp;
				DOWN(heap, index * 2, N);
			}
			else return;
		}
		else {
			if (vs(heap[index], heap[index * 2 + 1]) == heap[index * 2 + 1]) {
				tmp = heap[index];
				heap[index] = heap[index * 2 + 1];
				heap[index * 2 + 1] = tmp;
				DOWN(heap, index * 2 + 1, N);
			}
			else return;

		}
	}
	else {
		if (vs(heap[index], heap[index * 2]) == heap[index * 2]) {
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
	DOWN(heap, 1, N - 1);

	return tmp;
}
int main() {
	int *heap;
	int N;
	int i;
	int data;
	int stack = 1;
	scanf("%d", &N);
	heap = (int*)malloc(sizeof(int)*(N + 1));
	for (i = 1; i <= N; i++) {
		scanf("%d", &data);
		if (data != 0) {
			push(heap, data, stack++);
		}
		else {
			if (stack == 1) printf("0\n");
			else printf("%d\n", pop(heap, stack--));
		}
	}
	return 0;
}