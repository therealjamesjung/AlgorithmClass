#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *parent;
	struct Node *left_child, *right_child;
}ND;

void Insert_BST(ND *p, int data);
void inorder_traverse(ND *t);

ND *create_node(int data);

int main() {
	int N, i, j, data;
	ND *p, *root;
	scanf("%d", &data);
	root = create_node(data);
	while (scanf("%d", &data) != EOF) {
		Insert_BST(root, data);
	}

	inorder_traverse(root);

	return 0;
}


void Insert_BST(ND *p, int data) {
	ND *st;
	if (p->data > data) {
		if (p->left_child == NULL) {
			st = create_node(data);
			p->left_child = st;
			st->parent = p;
			return;
		}
		else Insert_BST(p->left_child, data);
	}
	else if (p->data < data) {
		if (p->right_child == NULL) {
			st = create_node(data);
			p->right_child = st;
			st->parent = p;
			return;
		}
		else Insert_BST(p->right_child, data);
	}
	else if (p->data == data) return;
}


void inorder_traverse(ND *t) {//중위순회
	if (t->left_child != NULL) inorder_traverse(t->left_child);
	if (t->right_child != NULL) inorder_traverse(t->right_child);
	printf("%d\n", t->data);
}

ND *create_node(int data) {
	ND *new_node = (ND *)malloc(sizeof(ND));

	new_node->data = data;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	new_node->parent = NULL;

	return new_node;
}
