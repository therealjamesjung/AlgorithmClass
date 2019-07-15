#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *next;
    int elem;
}Node;
Node *get_node(int a)
{
    Node *node;

    node=(Node*)malloc(sizeof(Node));
    node->next=NULL;
    node->elem=a;

    return node;
}
Node *make_list(int n)
{
    int i,a;
    Node *node=get_node(0),*head=node;

    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        node->next=get_node(a);
        node=node->next;
    }
    node = head->next;
    free(head);
    return node;
}
Node *bubble_sort(Node *node,int n)
{
    int i, j,tmp;
    Node *nodei=node,*nodej=node;

    for (i = 0; i < n; i++)
    {
        for (nodej=nodei,j=i; j < n ; j++)
        {
            if (nodei->elem > nodej->elem)
            {
                tmp = nodei->elem;
                nodei->elem = nodej->elem;
                nodej->elem = tmp;
            }
            nodej = nodej->next;
        }
        nodei = nodei->next;
    }
    return node;
}
void print_node(Node *node)
{
    while(node)
    {
        printf("%d\n",node->elem);
        node=node->next;
    }
}
void free_node(Node *node)
{
    Node *a;
    while (node)
    {
        a = node->next;
        free(node);
        node = a;
    }
}
int main()
{
    int n;
    Node *node;

    scanf("%d",&n);

    node=make_list(n);
    node=bubble_sort(node,n);

    print_node(node);

    free_node(node);
}
