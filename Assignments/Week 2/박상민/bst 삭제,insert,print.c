//
// Created by front on 2019-07-18.
//

#include<stdio.h>
typedef struct Node {
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int data;
}Node;
Node *get_node(Node*node, int data);
void insert_node(Node **root, int data);
void print_node(Node *root);
void *delete_node(Node **node, int data);
int main() {
    Node *root = NULL;
    int n, i, data, a;
    char ch = 0;
    /*
    while (scanf("%d", &data) != EOF){
       insert_node(&root, data);
    }
    */
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        insert_node(&root, data);
    }
    getchar();
    while (ch != 'f') {
        scanf("%c", &ch);
        if (ch == 'I') {
            insert_node(&root, data);
        }
        else if (ch == 'd') {
            scanf("%d", &a);
            getchar();
            delete_node(&root, a);
        }
        else if (ch == 'p') {
            print_node(root);
            printf("\n");
        }
    }
}
Node *successor_node(Node **node, int data) {
    Node *output = NULL;
    if ((*node)->data == data) //첫 번째 입력일 때
        successor_node(&(*node)->right, data);
    else {
        if ((*node)->left != NULL)
            successor_node(&(*node)->left, data);
        else if ((*node)->left == NULL) {
            output = *node;
            *node = NULL;
            return output;
        }
    }
}
void *delete_node(Node **node, int data) {
    Node *tmp = NULL, *ttmp = NULL,*tmpr=NULL,*tmpl=NULL;
    if ((*node)->data == data) {
        if ((*node)->left == NULL && (*node)->right == NULL) {
            (*node) = NULL;
        }
        else if ((*node)->left == NULL && (*node)->right != NULL) {
            tmp = (*node)->right;
            ttmp = (*node)->parent;
            (*node) = NULL;
            ttmp->left = tmp;
        }
        else if ((*node)->left != NULL && (*node)->right == NULL) {
            tmp = (*node)->left;
            ttmp = (*node)->parent;
            (*node) = NULL;
            ttmp->right = tmp;
        }
        else if ((*node)->left != NULL && (*node)->right != NULL) {
            tmp = successor_node(&(*node), data);
            tmpr = (*node)->right;
            tmpl = (*node)->left;
            (*node) = tmp;
            (*node)->right = tmpr;
            (*node)->left = tmpl;
        }
    }
    else if ((*node)->data < data) {
        delete_node(&(*node)->right, data);
    }
    else if ((*node)->data > data) {
        delete_node(&(*node)->left, data);
    }
}
Node *get_node(Node*node, int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    return newnode;
}
void insert_node(Node **node, int data) {
    if ((*node) == NULL) {//첫 번째일때
        (*node) = get_node(&(*node), data);
    }
    if ((*node)->data == data)
        return;
    else if ((*node)->data < data) {
        if ((*node)->right != NULL)
            insert_node(&(*node)->right, data);
        else {
            (*node)->right = get_node(*node, data);
            (*node)->right->parent = (*node);
        }
    }
    else if ((*node)->data > data) {
        if ((*node)->left != NULL)
            insert_node(&(*node)->left, data);
        else {
            (*node)->left = get_node(*node, data);
            (*node)->left->parent = (*node);
        }
    }
}
void print_node(Node *root) {
    if (root != NULL) {
        printf("%d\n", root->data);
        print_node(root->left);
        print_node(root->right);
    }
}