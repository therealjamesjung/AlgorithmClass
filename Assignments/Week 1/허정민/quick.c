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



void append(List *list) {
    Node *new_node = getNode();
    scanf("%d", &new_node->data);
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

List quick_sort(List *list) {
    int i;
    List left, right;
    Node *pivot = list->head->next, *p;
    if (list->length <= 1) return *list;
    setList(&left);
    setList(&right);
    for (i = 0; i < list->length / 2; i++) {
        pivot = pivot->next;
    }
    for (p = list->head->next; p;) {
        if (p == pivot) {
            p = p->next;
            continue;
        }
        if (p->data < pivot->data) {
            left.last->next = p;
            p = p->next;
            left.last = left.last->next;
            left.last->next = NULL;
            left.length++;
        }
        else {
            right.last->next = p;
            p = p->next;
            right.last = right.last->next;
            right.last->next = NULL;
            right.length++;
        }
    }

    left = quick_sort(&left);
    right = quick_sort(&right);
    pivot->next = NULL;

    left.last->next = pivot;
    left.last = left.last->next;
    if (right.length != 0) {
        left.last->next = right.head->next;
        left.last = right.last;
    }
    left.length += right.length + 1;
    return left;
}

void freeNode(Node *p) {
    if (p->next) freeNode(p->next);
    free(p);
}

int main() {
    int N, i;
    List list;
    setList(&list);
    scanf("%d", &N);
    for (i = 0; i < N; i++) append(&list);
    list=quick_sort(&list);
    print(list.head->next);
    freeNode(list.head->next);
    return 0;
}