#pragma warning (disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
typedef struct NODE {
	struct NODE *next;
	struct NODE *prev;
	int data;
}NODE;
NODE *getNode() {
	NODE *p;
	p = (NODE*)malloc(sizeof(NODE));
	p->next = NULL;
	p->prev = NULL;
	p->data = NULL;
	return p;
}
void add(NODE *h, int data) {
	NODE *new = h;
	NODE *tmp;
	if (new == NULL) {
		new = getNode();
		new->data = data;
	}
	else {
		tmp = getNode();
		tmp->prev = new;
		new->next = tmp;
		new = new->next;
		new->data = data;
	}
}
void insert(NODE *h) {
	NODE *set = h;
	NODE *p = h;
	NODE *tmp = h;
	int i, j;
	int flag = 0;
	while (p->prev != NULL) {
		if (p->prev->data <= tmp->data) break;
		p = p->prev;
		flag++;
	}
	if (h->next == NULL) {
		if (flag != 0) {
			tmp->prev->next = NULL;
			tmp->next = p;//�̵���
			p->prev->next = tmp;
			tmp->prev = p->prev;
			p->prev = tmp;
		}

	}
	else {
		if (flag != 0) {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			tmp->next = p;//�̵���
			p->prev->next = tmp;
			tmp->prev = p->prev;
			p->prev = tmp;
		}

		insert(set->next);
	}
}
void print(NODE *h) {
	NODE *show = h;
	for (; show != NULL; show = show->next) {
		printf(" %d", show->data);
	}
}
int main() {
	NODE *arr2;
	int N;
	int i;
	NODE *p;
	LARGE_INTEGER frequency;
	LARGE_INTEGER t1, t2;
	double elapsed_time;
	QueryPerformanceFrequency(&frequency);
	srand(time(NULL));
	scanf("%d", &N);
	arr2 = (NODE *)malloc(sizeof(NODE));
	p = arr2;

	for (i = 0; i < N; i++) {
		add(p, rand());
		p = p->next;
	}
	p->prev = NULL;
	//insertion_sort(arr1, n);  //
	//reverse_array(arr1, 0, n - 1); //

	QueryPerformanceCounter(&t1);
	insert(arr2->next);
	QueryPerformanceCounter(&t2);

	elapsed_time = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart; //get elapsed time in millisec

	printf("Time by insertion sort: %lf ms\n", elapsed_time);
	return 0;
}