#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left_child, *right_child, *parent;

}Node;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    new_node->parent = NULL;

    return new_node;
}

Node *find_node(Node *root, int data)
{
    if (root == NULL) return NULL;

    else if (root->data == data) return root;
    else if (root->data > data) return find_node(root->left_child, data);
    else return find_node(root->right_child, data);
}

void insert(Node *root, Node *node)
{
    if (root->left_child == NULL && root->right_child == NULL) // Leaf node
    {
        if (root->data > node->data) root->left_child = node;
        else root->right_child = node;

        node->parent = root;
    }
    else if (root->left_child == NULL) // Only has right_child
    {
        if (root->data > node->data)
        {
            root->left_child = node;
            node->parent = root;
        }
        else insert(root->right_child, node);
    }
    else if (root ->right_child == NULL) // Only has left_child
    {
        if (root->data > node->data) insert(root->left_child, node);
        else
        {
            root->right_child = node;
            node->parent = root;
        }
    }
    else // Has both child nodes
    {
        if (root->data > node->data) insert(root->left_child, node);
        else insert(root->right_child, node);
    }
}

Node *delete(Node *root, Node *node)
{
    Node *successor_node;
    if (node == NULL)
    {
        printf("Node with data was not found.");
        return root;
    }

    if (node->left_child == NULL && node ->right_child == NULL) // Node is leaf node
    {
        if (node->parent == NULL) // Attempt to delete the root node
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (node->parent->left_child != NULL && node->parent->left_child->data == node->data) // Node is left child of parent
        {
            node->parent->left_child = NULL;
        }
        else if (node->parent->right_child != NULL && node->parent->right_child->data == node->data)  // Node is right child of parent
        {
            node->parent->right_child = NULL;
        }
        free(node);
        node = NULL;
        return root;
    }

    else if (node->right_child == NULL) // Node only has left child node
    {
        node->left_child->parent = node->parent;
        if (node->parent == NULL) // Attempt to delete the root node
        {
            free(root);
            root = root->left_child;
            return root;
        }
        if (node->parent->left_child != NULL && node->parent->left_child->data == node->data) // Node is left child of parent
        {
            node->parent->left_child = node->left_child;
        }
        else if (node->parent->right_child != NULL && node->parent->right_child->data == node->data) // Node is right child of parent
        {
            node->parent->right_child = node->left_child;
        }
        free(node);
        node = NULL;
        return root;
    }

    else if (node->left_child == NULL) // Root only has right child node
    {
        node->right_child->parent = node->parent;
        if (node->parent == NULL) // Attempt to delete the root node
        {
            free(root);
            root = root->right_child;
            return root;
        }
        if (node->parent->left_child != NULL && node->parent->left_child->data == node->data) // Root is left child of parent
        {
            node->parent->left_child = node->right_child;
        }
        else if (node->parent->right_child != NULL && node->parent->right_child->data == node->data) // Root is right child of parent
        {
            node->parent->right_child = node->right_child;
        }
        free(node);
        node = NULL;
        return root;
    }

    else // Root has both child nodes
    {
        successor_node = node->right_child;
        while(successor_node->left_child != NULL) successor_node = successor_node->left_child; // Find successor node

        node->data = successor_node->data; // Swap root with successor node

        if (successor_node == node->right_child) // Successor node is root's right child
        {
            node->right_child = successor_node->right_child;
            if (successor_node->right_child != NULL)successor_node->right_child->parent = root;
        }
        else successor_node->parent->left_child = NULL;

        free(successor_node);
        successor_node = NULL;
        return root;
    }
}

void print_preorder(Node *root)
{
    if (root == NULL) return;

    printf("%d ", root->data);
    print_preorder(root->left_child);
    print_preorder(root->right_child);

}

int main()
{
    int n;
    char c;
    Node *root = NULL;

    while (1)
    {
        scanf("%c", &c);

        if (c == 'q') break;

        else if (c == 'i')
        {
            scanf("%d", &n);
            if (root == NULL) root = create_node(n);
            else insert(root, create_node(n));
            getchar();
        }
        else if (c == 'p')
        {
            print_preorder(root);
            printf("\n");
        }
        else if (c == 'd')
        {
            scanf("%d", &n);
            root = delete(root, find_node(root, n));
            getchar();
        }
    }

    return 0;
}