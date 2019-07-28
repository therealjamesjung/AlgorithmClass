#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data, height, balance_factor;
    struct Node *left_child, *right_child, *parent;

}Node;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->height = 1;
    new_node->balance_factor = 0;
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

int compare_max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *node)
{
    if (node == NULL) return 0;
    else return node->height;
}

void update_height(Node *node)
{
    if (node == NULL) return;

    node->height = compare_max(height(node->left_child), height(node->right_child)) + 1;
    update_height(node->parent);
}

void update_balance_factor(Node *node)
{
    if (node == NULL) return;

    node->balance_factor = height(node->left_child) - height(node->right_child);
    update_balance_factor(node->parent);
}

void *rotate_right(Node *target_node)
{
    Node *new_root = target_node->left_child;


    if (target_node->parent != NULL)
    {
        if (target_node->parent->left_child != NULL && target_node->parent->left_child->data == target_node->data)
        {
            target_node->parent->left_child = new_root;
        }
        else if (target_node->parent->right_child != NULL && target_node->parent->right_child->data == target_node->data)
        {
            target_node->parent->right_child = new_root;
        }
    }
    new_root->parent = target_node->parent;

    target_node->left_child = new_root->right_child;
    if (new_root->right_child != NULL) new_root->right_child->parent = target_node;

    new_root->right_child = target_node;
    target_node->parent = new_root;

    update_height(target_node);
    update_balance_factor(target_node);
}

void *rotate_left(Node *target_node)
{
    Node *new_root = target_node->right_child;


    if (target_node->parent != NULL)
    {
        if (target_node->parent->left_child != NULL && target_node->parent->left_child->data == target_node->data)
        {
            target_node->parent->left_child = new_root;
        }
        else if (target_node->parent->right_child != NULL && target_node->parent->right_child->data == target_node->data)
        {
            target_node->parent->right_child = new_root;
        }
    }
    new_root->parent = target_node->parent;

    target_node->right_child = new_root->left_child;
    if (new_root->left_child != NULL) new_root->left_child->parent = target_node;

    new_root->left_child = target_node;
    target_node->parent = new_root;

    update_height(target_node);
    update_balance_factor(target_node);
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

Node *rebalance(Node *node)
{
    if (node == NULL) return node;

    update_height(node);
    update_balance_factor(node);

    while (1)
    {
        if (abs(node->balance_factor) >= 2)
        {
            if (node->balance_factor > 1) // Left subtree's height is greater than right subtree
            {
                if (node->left_child->balance_factor < 0) rotate_left(node->left_child);
                rotate_right(node);
            }
            else if (node->balance_factor < -1) // Right subtree's height is greater than left subtree
            {
                if (node->right_child->balance_factor > 0) rotate_right(node->right_child);
                rotate_left(node);
            }
        }

        if (node->parent == NULL) break;
        node = node->parent;
    }
    return node;
}

Node *delete(Node *root, Node *node)
{
    Node *successor_node;
    if (node == NULL)
    {
        printf("X\n");
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

Node *find_delete_position(Node *node, int data)
{
    if (node->left_child == NULL && node->right_child == NULL) return node;

    else if (node->data > data)
    {
        if (node->left_child == NULL) return node;
        else return find_delete_position(node->left_child, data);
    }
    else
    {
        if (node->right_child == NULL) return node;
        return find_delete_position(node->right_child, data);
    }
}

void print_preorder(Node *root)
{
    if (root == NULL) return;

    printf(" %d", root->data);
    print_preorder(root->left_child);
    print_preorder(root->right_child);
}

Node *insert_into_AVL(Node *root, Node *node)
{
    insert(root, node);
    return rebalance(node);
}

Node *delete_from_AVL(Node *root, int n)
{
    Node *delete_node = find_node(root, n);
    if (delete_node == NULL) return root;
    root = delete(root, delete_node);
    if (root == NULL) return root;
    return rebalance(find_delete_position(root, n));
}

int main()
{
    int n;
    char c;
    Node *root = NULL, *tmp = NULL;

    while (1)
    {
        scanf("%c", &c);

        if (c == 'q') break;

        else if (c == 'i')
        {
            scanf("%d", &n);
            if (root == NULL) root = create_node(n);
            else root = insert_into_AVL(root, create_node(n));
            getchar();
        }
        else if (c == 's')
        {
            scanf("%d", &n);
            tmp = find_node(root, n);
            if (tmp != NULL) printf("%d\n", tmp->data);
            else printf("X\n");
        }
        else if (c == 'p')
        {
            print_preorder(root);
            printf("\n");
        }
        else if (c == 'd')
        {
            scanf("%d", &n);
            root = delete_from_AVL(root, n);
            getchar();
        }
    }

    return 0;
}