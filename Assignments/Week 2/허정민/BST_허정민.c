#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    struct Node *left, *right, *parent;
    int data;
}Node;

Node* getNode(int d) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    p->data = d;
    return p;
}

Node* searchNode(int data, Node *leaf) {
    Node *p;
    if (leaf->data == data) return leaf;
    if (leaf->left) {
        p = searchNode(data, leaf->left);
        if (!p) return p;
    }
    if (leaf->right) {
        p = searchNode(data, leaf->right);
        if (!p) return p;
    }
    return NULL;
}

void insert(Node *root,int d) {
    Node *new_node, *p = root;
    new_node = getNode(d);
    while (p) {
        if (p->data == d) return;
        if (p->data > d) {
            if (p->left == NULL) {
                p->left = new_node;
                new_node->parent = p;
                break;
            }
            else p = p->left;
        }
        else {
            if (p->right == NULL) {
                p->right = new_node;
                new_node->parent = p;
                break;
            }
            else p = p->right;
        }
    }
}

void printTree(Node *p) {
    if (p == NULL) return;
    printTree(p->left);
    printTree(p->right);
    printf("%d ", p->data);
}

void freeNode(Node *p) {
    if (p == NULL) return;
    freeNode(p->left);
    freeNode(p->right);
    free(p);
}

int main() {
    int N, tmp;
    Node *root;
    //scanf("%d", &N);
    scanf("%d", &tmp);
    root = getNode(tmp);
    //N--;
    while (scanf("%d",&tmp)!=EOF) {
        //scanf("%d", &tmp);
        insert(root, tmp);
    }
    printTree(root);
    freeNode(root);
}