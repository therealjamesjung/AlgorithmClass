#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
typedef struct Node
{
    struct Node *right, *left;
    int b_factor, height, elem;
}Node;
int max_num(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
Node *get_node(int a)
{
    Node *node = (Node*)malloc(sizeof(Node));

    node->right = NULL;
    node->left = NULL;

    node->elem = a;
    node->height = 1;
    node->b_factor = 0;

    return node;
}
void find_height_bfactor(Node *root)
{
    if (root->left != NULL && root->right != NULL)
    {
        root->height = max_num(root->left->height, root->right->height) + 1;
        root->b_factor = root->left->height - root->right->height;
    }
    else if (root->left == NULL && root->right != NULL)
    {
        root->height = root->right->height + 1;
        root->b_factor = -root->right->height;
    }
    else if (root->left != NULL && root->right == NULL)
    {
        root->height = root->left->height + 1;
        root->b_factor = root->left->height;
    }
    else
    {
        root->height = 1;
        root->b_factor = 0;
    }
}
Node *rotate_right(Node *node)
{
    Node *tmp, *balanced_root;

    tmp = node->left->right;
    node->left->right = node;
    balanced_root = node->left;
    node->left = tmp;

    find_height_bfactor(node);
    find_height_bfactor(balanced_root);

    return balanced_root;
}
Node *rotate_left(Node *node)
{
    Node *tmp, *balanced_root;

    tmp = node->right->left;
    node->right->left = node;
    balanced_root = node->right;
    node->right = tmp;

    find_height_bfactor(node);
    find_height_bfactor(balanced_root);

    return balanced_root;
}
Node *balance_node(Node *root, Node *mother)
{
    if (abs(root->b_factor) >= 2)
    {
        if (root->b_factor > 1)
        {
            if (root->left->b_factor < 0)
                root->left = rotate_left(root->left);
            root = rotate_right(root);
        }
        else if (root->b_factor < -1)
        {
            if (root->right->b_factor > 0)
                root->right = rotate_right(root->right);
            root = rotate_left(root);
        }
    }
    if (mother != NULL)
        find_height_bfactor(mother);
    return root;
}
void insert_node(Node *root, int a)
{
    if (a == root->elem)
        return;
    else
    {
        if (a < root->elem)
        {
            if (root->left == NULL)
                root->left = get_node(a);
            else
                insert_node(root->left, a);
        }
        else if (a > root->elem)
        {
            if (root->right == NULL)
                root->right = get_node(a);
            else
                insert_node(root->right, a);
        }
        find_height_bfactor(root);
        if (root->left != NULL)
            root->left = balance_node(root->left, root);
        if (root->right != NULL)
            root->right = balance_node(root->right, root);
    }
}
Node *search_node(Node *node, int a)
{
    if (node == NULL)
        return NULL;
    else if (node->elem == a)
        return node;
    else if (a < node->elem)
        search_node(node->left, a);
    else if (a > node->elem)
        search_node(node->right, a);
}
Node *deleting(Node *node)
{
    Node *tmp=NULL, *p_tmp;
    if (node->left == NULL && node->right == NULL)
    {
        free(node);
        return NULL;
    }
    else
    {
        if (node->left != NULL && node->right != NULL)
        {
            tmp = node->right;
            p_tmp = node;
            if (tmp->left != NULL)
            {
                while (tmp->left != NULL)
                {
                    p_tmp = tmp;
                    tmp = tmp->left;
                }
                p_tmp->left = tmp->right;
                tmp->right = node->right;
            }

            tmp->left = node->left;
            free(node);
            node = NULL;

            return tmp;
        }
        else if (node->left != NULL || node->right != NULL)
        {
            if (node->left == NULL)
            {
                tmp = node->right;
                free(node);
                node = NULL;
                return tmp;
            }
            else if (node->right == NULL)
            {
                tmp = node->left;
                free(node);
                node = NULL;
                return tmp;
            }
        }
    }
}
void delete_node(Node *node, int a)
{
    if (node->left->elem == a)
        node->left = deleting(node->left);
    else if (node->right->elem == a)
        node->right = deleting(node->right);
    else
    {
        if (a < node->elem)
            delete_node(node->left, a);
        else
            delete_node(node->right, a);
    }
}
void rebalance(Node *root)
{
    if (root == NULL)
        return;
    else
    {
        rebalance(root->left);
        rebalance(root->right);
        find_height_bfactor(root);
        if (root->left != NULL)
            root->left = balance_node(root->left, root);
        if (root->right != NULL)
            root->right = balance_node(root->right, root);
    }
}
void print_node(Node *node)
{
    if (node == NULL)
        return;
    printf(" %d", node->elem);
    print_node(node->left);
    print_node(node->right);
}
int main()
{
    int first = 0, a;
    char ch;
    Node *node = NULL, *tmp;

    while (1)
    {
        scanf("%c", &ch);

        if (ch == 'q')
            break;
        else if (ch == 'i')
        {
            scanf("%d", &a);
            if (first == 0)
            {
                node = get_node(a);
                ++first;
            }
            else
            {
                insert_node(node, a);
                node = balance_node(node, NULL);
            }
        }
        else if (ch == 'p')
        {
            print_node(node);
            printf("\n");
        }
        else if (ch == 's')
        {
            scanf("%d", &a);
            tmp = search_node(node, a);
            if (tmp == NULL)
                printf("X\n");
            else
                printf("%d\n", tmp->elem);
        }
        else if (ch == 'd')
        {
            scanf("%d", &a);
            tmp = search_node(node, a);
            if (tmp == NULL)
                printf("X\n");
            else
            {
                if (a == node->elem)
                    node = deleting(node);
                else
                    delete_node(node, a);
                if (node != NULL)
                {
                    rebalance(node);
                    node = balance_node(node, NULL);
                }
                else
                    first = 0;
            }
        }
        getchar();
    }
}
