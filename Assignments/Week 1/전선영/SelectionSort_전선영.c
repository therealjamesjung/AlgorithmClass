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
Node *select_min(Node *node)
{
    Node *minn=node;
    while (node)
    {
        if (node->elem < minn->elem)
            minn = node;
        node = node->next;
    }
    return minn;
}
Node *selection_sort(Node *head)
{
    Node *minn, *node=head;
    int tmp;
    while (head)
    {
        minn = select_min(head);
        if (minn->elem < head->elem)
        {
            tmp=head->elem;
            head->elem = minn->elem;
            minn->elem = tmp;
        }
        head = head->next;
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
    node=selection_sort(node);

    print_node(node);

    free_node(node);
}
