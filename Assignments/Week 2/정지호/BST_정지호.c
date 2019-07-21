#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	struct node* left, * right;
	int id;
}Node;
void insert_tree(Node** Root, int num);
void Remove_tree(Node* DT, Node** Root, Node** Parent);
Node* Remove_node(Node* node);
void Preorder_traverse(Node* Root);
void Inorder_traverse(Node* Root);
Node* find_tree(Node* Root, int num);
Node* find_Parent(Node* Root, Node** Parent, int num);
Node* getnode(int data);
int main()
{
	Node* Root = NULL,* PR = NULL, * Parent = NULL;
	int i;
	int N, num;
	char menu;

	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		getchar();
		scanf("%c %d", &menu, &num);

		switch (menu)
		{
		case'I':
			insert_tree(&Root, num);
			break;
		case'P':
			switch (num)
			{
			case 1:
				Preorder_traverse(Root);
				if (Root == NULL)printf("NULL");
				printf("\n");
				break;
			case 2:
				Inorder_traverse(Root);
				printf("\n");
				break;
			}
			break;
		case'D':
			PR = find_Parent(Root, &Parent, num);
			Remove_tree(PR, &Root, &Parent);
			Parent = NULL;
			break;
		}
	}


}
void insert_tree(Node * *Root, int num)
{
	if (*Root != NULL)
	{
		if (num < (*Root)->id)
			insert_tree(&(*Root)->left, num);
		else if (num > (*Root)->id)
			insert_tree(&(*Root)->right, num);
	}
	else
		*Root = getnode(num);
}
void Remove_tree(Node * DT, Node * *Root, Node * *Parent)
{

	if (DT == NULL)
		printf("No Data\n");
	else if (DT == *Root) * Root = Remove_node(DT);
	else if (DT == (*Parent)->left)
		(*Parent)->left = Remove_node(DT);
	else if (DT == (*Parent)->right)
		(*Parent)->right = Remove_node(DT);
	return;
}
Node * Remove_node(Node * node)
{
	Node* Parent = NULL, * R = NULL;
	if (node->left == NULL && node->right == NULL) return NULL;
	else if (node->left == NULL && node->right != NULL)
		return node->right;
	else if (node->left != NULL && node->right == NULL)
		return node->left;
	else
	{
		R = node->right;
		while (R->left != NULL)
		{
			Parent = R;
			R = R->left;
		}
		node->id = R->id;
		if (R == node->right) node->right = R->right;
		else Parent->left = R->right;
		return node;
	}
}
void Preorder_traverse(Node * Root)
{
	if (Root != NULL)
	{
		printf("%d ", Root->id);
		Preorder_traverse(Root->left);
		Preorder_traverse(Root->right);
	}
}
void Inorder_traverse(Node * Root)
{
	if (Root != NULL)
	{
		Inorder_traverse(Root->left);
		printf("%d ", Root->id);
		Inorder_traverse(Root->right);

	}
}
Node* find_tree(Node * Root, int num)
{
	Node* result = NULL;

	if (Root == NULL) return NULL;
	if (Root->id == num) return Root;
	if (Root->left != NULL)
		result = find_tree(Root->left, num);
	if (result == NULL)
		result = find_tree(Root->right, num);
	return result;
}
Node * find_Parent(Node * Root, Node * *Parent, int num)
{
	Node* result = NULL;

	if (Root == NULL) return NULL;
	if (Root->id == num) return Root;
	if (Root->left != NULL)
	{
		*Parent = Root;
		result = find_Parent(Root->left, Parent, num);
	}
	if (result == NULL)
	{
		*Parent = Root;
		result = find_Parent(Root->right, Parent, num);
	}
	return result;
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