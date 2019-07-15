#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *next, *prev;
    int data;
}Node;

Node* getNode() {
    Node *p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void print(Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void freeNode(Node *p) {
    if (p->next) freeNode(p->next);
    free(p);
}

void insert_sort(Node *arr) {
    Node *p, *q;
    for (p = arr->next->next; p; p = p->next) {
        for (q = arr->next; q->data <= p->data&&p != q; q = q->next);
        if (p == q) continue;
        p->prev->next = p->next;
        if(p->next) p->next->prev = p->prev;
        q->prev->next = p;
        p->next = q;
        p->prev = q->prev;
        q->prev = p;
    }
}

int main() {
    int N, i;
    Node *list = getNode(), *p = list;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        p->next = getNode();
        p->next->prev = p;
        scanf("%d", &p->next->data);
        p = p->next;
    }
    insert_sort(list);
    print(list->next);
    freeNode(list);
    return 0;
}