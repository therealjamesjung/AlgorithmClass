#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *next;
    int data;
}Node;

typedef struct List {
    Node *head, *last;
    int length;
}List;

Node* getNode() {
    Node *p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    return p;
}

void setList(List *list) {
    list->head = getNode();
    list->last = list->head;
    list->length = 0;
}

List merge(List *left, List *right) {
    Node *p = left->head->next, *q = right->head->next;
    List list;
    setList(&list);
    list.length = left->length + right->length;
    while (p&&q) {
        if (p->data > q->data) {
            list.last->next = q;
            list.last = list.last->next;
            q = q->next;
        }
        else {
            list.last->next = p;
            list.last = list.last->next;
            p = p->next;
        }
    }
    while (p) {
        list.last->next = p;
        list.last = list.last->next;
        p = p->next;
    }
    while (q) {
        list.last->next = q;
        list.last = list.last->next;
        q = q->next;
    }
    return list;
}
List merge_sort(List *list) {
    int i;
    List left, right;
    Node *p = list->head->next;
    if (list->length == 1) return *list;
    setList(&left);
    setList(&right);
    left.head->next = p;
    for (i = 0; i < list->length / 2 - 1; i++) {
        p = p->next;
    }
    left.last = p;
    right.head->next = p->next;
    left.last->next = NULL;
    right.last = list->last;
    left.length = list->length / 2;
    right.length = list->length - left.length;
    left = merge_sort(&left);
    right = merge_sort(&right);
    return merge(&left, &right);
}

void append(List *list) {
    Node *new_node = getNode();
    scanf("%d",&new_node->data);
    list->last->next = new_node;
    list->last = new_node;
    list->length++;
}

void print(Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void freeNode(Node *p) {
    if(p->next) freeNode(p->next);
    free(p);
}

int main() {
    int N, i;
    List list;
    setList(&list);
    scanf("%d", &N);
    for (i = 0; i < N; i++) append(&list);
    list = merge_sort(&list);
    print(list.head->next);
    freeNode(list.head->next);
    return 0;
}