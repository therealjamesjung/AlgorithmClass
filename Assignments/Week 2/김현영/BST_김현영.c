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

void PreOrder(Node* root)
{
	if (root == NULL) return;
	printf("%d ", root->elem);
	PreOrder(root->left);
	PreOrder(root->right);
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

Node* SuccessorNode(Node* node)
{
	if (node->left == NULL)
		return node;
	else
		SuccessorNode(node->left);
}


void Delete(Node** tree, int data)
{
	int tmpnum;
	Node* tmp = *tree, * child = NULL, * parent = NULL, * successor = NULL;

	tmp = Find(*tree, data);

	if (tmp->left == NULL && tmp->right == NULL) // child 0
	{
		if (tmp->parent)
		{
			parent = tmp->parent;
			if (parent->left == tmp)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		else *tree = NULL;
		return;
	}

	else if ((tmp->left == NULL) || (tmp->right == NULL))  //child 1
	{
		if (tmp->left == NULL)
			child = tmp->right;
		else
			child = tmp->left;
		if (tmp->parent)
		{
			parent = tmp->parent;
			if (parent->left == tmp)
				parent->left = child;
			else
				parent->right = child;
			child->parent = parent;
		}
		else
			*tree = child;
	}
	else //child 2
	{
		successor = SuccessorNode(tmp->right);
		tmpnum = tmp->elem;
		tmp->elem = successor->elem;
		successor->elem = tmpnum;
		Delete(&successor, successor->elem);
	}
}



int main() {
	Node* root = NULL;
	int i, n, data;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &data);
		Insert(&root, data);
	}
	PreOrder(root);
	printf("\ndelete start : ");

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &data);
		Delete(&root, data);
	}
	PreOrder(root);
}