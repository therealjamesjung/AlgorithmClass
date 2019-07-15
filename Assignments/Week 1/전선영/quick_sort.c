#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *next,*end;
    int elem;
}Node;
Node *get_node(int a)
{
    Node *node;

    node=(Node*)malloc(sizeof(Node));
    node->next=NULL;
    node->end=NULL;
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
Node *quick_sort(Node *node)
{
    Node *pivot = node, *left = get_node(0), *right = get_node(0);
    Node *left_head = left, *right_head = right;

    if (node->next == NULL)
    {
        node->end = node;
        return node;
    }
    else
    {
        node = node->next;
        while (node)
        {
            if (node->elem < pivot->elem)
            {
                left->next = node;
                left = left->next;
                left_head->next->end = left;
            }
            else
            {
                right->next = node;
                right = right->next;
                right_head->next->end = right;
            }
            node = node->next;
        }
    }

    left->next = NULL;
    right->next = NULL;
    pivot->next = NULL;

    left = left_head->next;
    right = right_head->next;
    free(left_head);
    free(right_head);

    if (left == NULL)
    {
        node = pivot;
        pivot->next = quick_sort(right);
        pivot->end = pivot->next->end;
        node->end = pivot->end;
    }
    else if (right == NULL)
    {
        node = quick_sort(left);
        node->end->next = pivot;
        node->end = pivot;
    }
    else
    {
        node = quick_sort(left);
        node->end->next = pivot;
        pivot->next = quick_sort(right);
        pivot->end = pivot->next->end;
        node->end = pivot->end;
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
    node=quick_sort(node,n);

    print_node(node);

    free_node(node);
}
