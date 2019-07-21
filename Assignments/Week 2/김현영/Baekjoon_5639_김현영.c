#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int elem;
	struct Node* left, * right, * parent;
}Node;

Node* createnode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->elem = data;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void PostOrder(Node* root)
{
	if (root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->elem);
}

Node* Find(Node* tree, int data)
{
	if (tree->elem > data)
	{
		if (tree->left == NULL)
			return tree;
		else Find(tree->left, data);
	}
	else if (tree->elem < data)
	{
		if (tree->right == NULL) return tree;
		else Find(tree->right, data);
	}
	else return tree;
}

void Insert(Node** tree, int data)
{
	Node* tmp = *tree;
	if (*tree == NULL)
		* tree = createnode(data);
	else
	{
		tmp = Find(*tree, data);
		if (tmp->elem > data)
		{
			tmp->left = createnode(data);
			tmp->left->parent = tmp;
		}
		else
		{
			tmp->right = createnode(data);
			tmp->right->parent = tmp;
		}
	}
}


int main()
{
	int data, n;
	Node* root = NULL;

	while (scanf("%d", &data) != EOF)
		Insert(&root, data);

	PostOrder(root);

}