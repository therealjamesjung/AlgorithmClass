#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left_child, *right_child;
}Node;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

Node *find_node(Node *root, int data)
{
    if (root == NULL) return NULL;

    else if (root->data == data) return root;
    else if (root->data > data) return find_node(root->left_child, data);
    else return find_node(root->right_child, data);
}

void insert(Node *root, Node *node)
{
    if (root->left_child == NULL && root->right_child == NULL) // Leaf node
    {
        if (root->data > node->data) root->left_child = node;
        else root->right_child = node;
    }
    else if (root->left_child == NULL) // Only has right_child
    {
        if (root->data > node->data) root->left_child = node;
        else insert(root->right_child, node);
    }
    else if (root ->right_child == NULL) // Only has left_child
    {
        if (root->data > node->data) insert(root->left_child, node);
        else root->right_child = node;
    }
    else // Has both child nodes
    {
        if (root->data > node->data) insert(root->left_child, node);
        else insert(root->right_child, node);
    }
}

void print_postorder(Node *root)
{
    if (root == NULL) return;

    print_postorder(root->left_child);
    print_postorder(root->right_child);
    printf("%d\n", root->data);
}

int main()
{
    int n;
    Node *root = NULL;


    while (scanf("%d", &n) != EOF)
    {
        if (root == NULL) root = create_node(n);
        else insert(root, create_node(n));
    }
    print_postorder(root);

    return 0;
}