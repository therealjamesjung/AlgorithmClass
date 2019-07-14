#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node* create_node(int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}
void makelist(Node** arr);
Node* merge_sort(Node* left, Node* right, int first, int end);
Node* Divide(Node* arr, int first, int end);

int main()
{
	int i, n;
	Node *arr = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		makelist(&arr);

	arr = Divide(arr, 0, n - 1);
	while (arr) {
		printf("%d ", arr->data);
		arr = arr->next;
	}
	free(arr);
}

void makelist(Node** arr)
{
	int num;
	Node* p = *arr;
	scanf("%d", &num);
	if (p == NULL)
		* arr = create_node(num);
	else {
		while (p->next)
			p = p->next;
		p->next = create_node(num);
	}
}

Node* merge_sort(Node* left, Node* right, int first, int end)
{
	Node* tmp = NULL, * p = tmp;
	int size, mid;
	while (1) {
		if (left->data < right->data)
		{
			if (tmp == NULL) {
				tmp = create_node(left->data);
				p = tmp;
			}
			else
			{
				tmp->next = create_node(left->data);
				tmp = tmp->next;
			}
			left = left->next;
		}
		else
		{
			if (tmp == NULL) {
				tmp = create_node(right->data);
				p = tmp;
			}
			else
			{
				tmp->next = create_node(right->data);
				tmp = tmp->next;
			}
			right = right->next;
		}
		if (left == NULL || right == NULL) break;
	}
	while (left)
	{
		tmp->next = create_node(left->data);
		tmp = tmp->next;
		left = left->next;
	}

	while (right) {
		tmp->next = create_node(right->data);
		tmp = tmp->next;
		right = right->next;
	}
	return p;
}

Node* Divide(Node* arr, int first, int end) {
	int i;
	int mid = (end + first) / 2;
	Node* left, * right, * temp;
	if (end - first == 0) return arr;
	left = arr;
	right = arr;
	for (i = first; i < mid; i++) {
		right = right->next;
		arr = arr->next;
	}
	right = right->next;
	arr->next = NULL;

	left = Divide(left, first, mid);
	right = Divide(right, mid + 1, end);
	left = merge_sort(left, right, first, end);
	return left;
}