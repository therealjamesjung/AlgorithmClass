#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Swap(int *a, int *b);
int Absolute(int a, int b);
void UpHeap(int *p, int index);
void DownHeap(int *p, int a, int b);

int main() {
	int *p, N, i, j, data, index = 1;

	scanf("%d", &N);
	p = (int *)malloc(sizeof(int) * (N + 1));
	for (i = 1; i <= N; i++) {
		scanf("%d", &data);
		if (data == 0) {
			if (index == 1) {
				printf("0\n");
				continue;
			}
			printf("%d\n", p[1]);
			p[1] = p[--index];
			DownHeap(p, 1, index);
		}
		else {
			p[index] = data;
			UpHeap(p, index++);
		}
	}

	return 0;
}


void UpHeap(int *p, int index) {
	if (index == 1 || Absolute(p[index], p[index / 2]) == p[index / 2]) return;
	else {
		Swap(&p[index], &p[index / 2]);
		UpHeap(p, index / 2);
	}
}

void DownHeap(int *p, int a, int b) {
	if (a * 2 > b) return;
	else if (a * 2 < b) {
		if (Absolute(p[a * 2], p[a * 2 + 1]) == p[a * 2]) {
			if (Absolute(p[a], p[a * 2]) == p[a * 2]) {
				Swap(&p[a], &p[a * 2]);
				DownHeap(p, a * 2, b);
			}
			else return;
		}
		else {
			if (Absolute(p[a], p[a * 2 + 1]) == p[a * 2 + 1]) {
				Swap(&p[a], &p[a * 2 + 1]);
				DownHeap(p, a * 2 + 1, b);
			}
			else return;
		}
	}
	else {
		if (Absolute(p[a], p[a * 2]) == p[a * 2]) {
			Swap(&p[a], &p[a * 2]);
			DownHeap(p, a * 2, b);
		}
		else return;
	}
}

int Absolute(int a, int b) {
	int x = a, y = b;
	if (a <= 0) x = a * (-1);
	if (b <= 0) y = b * (-1);
	if (x < y) return a;
	else if (x > y) return b;
	else if (a < b) return a;
	else if (a > b) return b;
}

void Swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}