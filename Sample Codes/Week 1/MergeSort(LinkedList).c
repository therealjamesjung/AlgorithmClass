#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

void divide(Node *node, int n)
{
    int i;
    for (i = 0; i < n - 1; i++) node = node->next;

    node->next = NULL;
}
void merge(Node *left, Node *right)
{
    Node *tmp = (Node *)malloc(sizeof(Node));

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            tmp->next = left;
            left = left->next;
        }
        else
        {
            tmp->next = right;
            right = right->next;
        }

        tmp = tmp->next;
    }

    while (left != NULL)
    {
        tmp->next = left;
        left = left->next;
        tmp = tmp->next;
    }

    while (right != NULL)
    {
        tmp->next = right;
        right = right->next;
        tmp = tmp->next;
    }
}

Node *merge_sort(Node *node, int cnt)
{
    int i;
    Node *left, *right;
    if (node->next == NULL) return node;

    left = node;
    right = node;

    for (i = 0; i < cnt / 2; i++) right = right->next;

    divide(node, cnt / 2);

    left = merge_sort(left, cnt / 2);

    if (cnt % 2 == 1) right = merge_sort(right, cnt / 2 + 1);
    else right = merge_sort(right, cnt / 2);

    merge(left, right);

    if (left->data <= right->data) return left;
    else return right;
}

int main()
{
    int n, i, tmp;
    Node *node;

    scanf("%d", &n);

    node = (Node *)malloc(sizeof(Node) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        node[i] = *create_node(tmp);
    }
    for (i = 0; i < n - 1; i++) (node + i)->next = (node + i + 1);

    node = merge_sort(node, n);

    while (node != NULL)
    {
        printf(" %d", node->data);
        node = node->next;
    }

    free(node);

    return 0;
}
