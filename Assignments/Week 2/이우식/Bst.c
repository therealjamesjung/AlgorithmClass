#pragma warning (disable :4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE {
	struct NODE *parent;
	struct NODE *left;
	struct NODE *right;
	int data;
}NODE;
NODE *getNode() {
	NODE *p;
	p = (NODE*)malloc(sizeof(NODE));
	p->data = NULL;
	p->left = NULL;
	p->right = NULL;
	p->parent = NULL;
	return p;
}
void Bprint(NODE *p) {
	if (p->left != NULL) Bprint(p->left);
	if (p->right != NULL) Bprint(p->right);
	printf("%d\n", p->data);
}
void insert(NODE *h, int data) {
	NODE *p = h;
	NODE *tmp;
	if (h->data == data) return;
	if (data < p->data) {
		if (p->left != NULL) {
			insert(p->left, data);
		}
		else
		{
			tmp = getNode();
			tmp->parent = p;
			tmp->data = data;
			p->left = tmp;
		}
	}
	else if (data > p->data) {
		if (p->right != NULL) {
			insert(p->right, data);
		}
		else
		{
			tmp = getNode();
			tmp->parent = p;
			tmp->data = data;
			p->right = tmp;
		}
	}
}
void FR(NODE *p) {
	if (p->left != NULL) FR(p->left);
	if (p->right != NULL) FR(p->right);
	free(p);
}
int main() {
	NODE *h;
	NODE *tmp;
	int i=0;
	int data;
	h = getNode();
	while ((scanf("%d", &data) != EOF)) {
		if (i == 0) {
			h->data = data;
			i++;
			continue;
		}
		insert(h, data);
	}
	Bprint(h);
	FR(h);
	return 0;
}