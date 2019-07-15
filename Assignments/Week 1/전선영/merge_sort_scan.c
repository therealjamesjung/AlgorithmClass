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
Node *merge_node(Node *node1, Node*node2)
{
    Node *node = get_node(0), *pnode = node;
    while (node1 != NULL || node2 != NULL)
    {
        if (node1 == NULL)
        {
            node->next = node2;
            node2 = node2->next;
        }
        else if (node2 == NULL)
        {
            node->next = node1;
            node1 = node1->next;
        }
        else if (node1->elem<node2->elem)
        {
            node->next = node1;
            node1 = node1->next;
        }
        else if(node1->elem>node2->elem)
        {
            node->next = node2;
            node2 = node2->next;
        }
        else
        {
            node->next = node1;
            node2 = node2->next;
            node1 = node1->next;
        }
        node = node->next;
    }
    node = pnode->next;
    free(pnode);
    return node;
}
Node *merge_sort(Node *node, int n)
{
    Node *node_r, *node_l = node;
    int i;
    if (node->next == NULL)
        return node;

    for (i = 1; i < n / 2; i++)
        node = node->next;

    node_r = node->next;
    node->next = NULL;

    if (n % 2 == 0)
        return merge_node(merge_sort(node_l, n / 2), merge_sort(node_r, n / 2));
    else
        return merge_node(merge_sort(node_l, n / 2), merge_sort(node_r, n / 2 + 1));
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
    if (node)
    {
        free_node(node->next);
        free(node);
    }
}
int main()
{
    int n;
    Node *node;

    scanf("%d",&n);

    node=make_list(n);
    node=merge_sort(node,n);

    print_node(node);

    free_node(node);
}
