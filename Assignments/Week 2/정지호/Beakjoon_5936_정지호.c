#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	struct node* left, * right;
	int id;
}Node;
void Postorder_traverse(Node* Root);
Node* getnode(int data);
Node* PreOrder_GetNode(Node ** Root, int data);
int main()
{
	Node* Root = NULL;
	int num;


	while (scanf("%d", &num) != EOF)
		PreOrder_GetNode(&Root,num);
	Postorder_traverse(Root);
}
void Postorder_traverse(Node* Root)
{
	if (Root != NULL)
	{
		Postorder_traverse(Root->left);
		Postorder_traverse(Root->right);
		printf("%d\n", Root->id);
	}
}
Node* getnode(int data)
{
	Node* Newnode;
	Newnode = (Node*)malloc(sizeof(Node));
	Newnode->id = data;
	Newnode->left = NULL;
	Newnode->right = NULL;
	return Newnode;
}
Node* PreOrder_GetNode(Node** Root, int data)
{
	if (*Root == NULL)
		* Root = getnode(data);
	else if ((*Root)->id == data)
		return NULL;
	else if ((*Root)->id > data)
		PreOrder_GetNode(&(*Root)->left, data);
	else if ((*Root)->id < data)
		PreOrder_GetNode(&(*Root)->right, data);
}

