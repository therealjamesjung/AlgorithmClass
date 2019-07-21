#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
LARGE_INTEGER Frequency;
LARGE_INTEGER BeginTime;
LARGE_INTEGER Endtime;
typedef struct Node
{
    struct Node *left, *right;
    int elem;
}Node;
Node *get_node(int a)
{
    Node *node;

    node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;

    node->elem = a;

    return node;
}
void insert_node(Node *root, int a)
{
    if (a == root->elem)
        return;
    else if (a < root->elem)
    {
        if (root->left == NULL)
            root->left = get_node(a);
        insert_node(root->left, a);
    }
    else if (a > root->elem)
    {
        if (root->right == NULL)
            root->right = get_node(a);
        insert_node(root->right, a);
    }
}
Node *make_tree()
{
    int a, first = 0;
    Node *root=NULL,*node;

    while (scanf("%d", &a) != EOF)
    {
        if (first == 0)
        {
            root = get_node(a);
            node = root;
            ++first;
        }
        else
            insert_node(root, a);
    }

    return root;
}
void print_node(Node *node)
{
    if(node == NULL)
        return ;
    print_node(node->left);
    printf("%d\n", node->elem);
    print_node(node->right);
}
int main()
{
    int n;
    Node *node;

    node = make_tree();

    print_node(node);

}