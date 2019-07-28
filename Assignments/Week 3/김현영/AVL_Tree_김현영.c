#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node {
    int data;
    struct Node* left, * right, * parent;
}Node;

Node* create_Node(int num);
int Get_Height(Node* node);
int Get_BF(Node* node);
Node* R_Rotation(Node* node);
Node* L_Rotation(Node* node);
Node* Rebalance(Node* node);
Node* Find(Node* tree, int num);
Node* Insert(Node** tree, int num);
Node* SuccessorNode(Node* node);
Node* Delete(Node** tree, int num);
Node* Search(Node* root, int num);
void Print(Node* root);


int main()
{
    char op;
    int num;
    Node* root = NULL, *node;

    while (1)
    {
        scanf("%c", &op);

        if (op == 'i')
        {
            scanf("%d", &num);
            root=Insert(&root, num);
        }
        else if (op == 's')
        {
            scanf("%d", &num);
            node = Search(root, num);
            if (node == NULL) printf("X\n");
            else printf("%d\n", node->data);
        }

        else if (op == 'd')
        {
            scanf("%d", &num);
            root=Delete(&root, num);
        }

        else if (op == 'p')
        {
            Print(root);
            printf("\n");
        }

        else if (op == 'q')
            break;
        getchar();
    }

}



Node* create_Node(int num)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = num;
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int Get_Height(Node* node)
{
    int left_h, right_h;
    if (node == NULL)	return 0;
    else
    {
        left_h = Get_Height(node->left);
        right_h = Get_Height(node->right);
        return 1 + (left_h > right_h ? left_h : right_h);
    }
}

int Get_BF(Node* node)
{
    if (node == NULL) return 0;
    else return Get_Height(node->left) - Get_Height(node->right);
}

Node* R_Rotation(Node* node)
{
    Node* newnode = node->left;
    Node* newleft = newnode->right;
    Node* parent = node->parent;

    newnode->parent = parent;
    node->parent = newnode;
    newnode->right = node;
    node->left = NULL;

    if (parent != NULL) //parent o
    {
        if (parent->data < node->data) parent->right = newnode;
        else parent->left = newnode;
    }

    if (newleft) //newnode.left.child o
    {
        node->left = newleft;
        newleft->parent = node;
    }
    return newnode;
}

Node* L_Rotation(Node* node)
{
    Node* newnode = node->right;
    Node* newright = newnode->left;
    Node* parent = node->parent;

    newnode->parent = parent;
    node->parent = newnode;
    newnode->left = node;
    node->right = NULL;

    if (parent != NULL) //parent o
    {
        if (parent->data < node->data)
            parent->right = newnode;
        else
            parent->left = newnode;
    }

    if (newright) //newnode.right.child o
    {
        node->right = newright;
        newright->parent = node;
    }

    return newnode;

}

Node* Rebalance(Node* node)  //return root
{
    int bf;
    while (1)
    {
        bf = Get_BF(node);
        if (abs(bf) >= 2)
        {
            if (bf > 1)
            {
                if (Get_BF(node->left) < 0)
                    node->left = L_Rotation(node->left);
                node = R_Rotation(node);
            }
            else if (bf < 1)
            {
                if (Get_BF(node->right) > 0)
                    node->right = R_Rotation(node->right);
                node = L_Rotation(node);
            }
        }
        if (node->parent == NULL) return node;
        node = node->parent;
    }
}

Node* Find(Node* tree, int num)
{
    if (tree->data > num)
    {
        if (tree->left == NULL)	return tree;
        else Find(tree->left, num);
    }
    else if (tree->data < num)
    {
        if (tree->right == NULL) return tree;
        else Find(tree->right, num);
    }
    else return tree;
}

Node* Insert(Node** tree, int num)
{
    Node* tmp = *tree;
    if (*tree == NULL)
        * tree = create_Node(num);
    else
    {
        tmp = Find(*tree, num);
        if (tmp->data > num)
        {
            tmp->left = create_Node(num);
            tmp->left->parent = tmp;
            *tree = Rebalance(tmp->left);
        }
        else
        {
            tmp->right = create_Node(num);
            tmp->right->parent = tmp;
            *tree = Rebalance(tmp->right);
        }
        return *tree;
    }
}

Node* SuccessorNode(Node* node)
{
    if (node->left == NULL)
        return node;
    else
        SuccessorNode(node->left);
}

Node* Delete(Node** tree, int num)
{
    int tmpnum;
    Node* tmp = NULL, * child = NULL, * parent = NULL, * successor = NULL;

    tmp = Search(*tree, num);
    if (tmp == NULL)
    {
        printf("X\n");
        return *tree;
    }

    if (tmp->left == NULL && tmp->right == NULL) //child 0
    {
        if (tmp->parent)  //parent o
        {
            parent = tmp->parent;
            if (parent->left == tmp)
                parent->left = NULL;
            else
                parent->right = NULL;
            *tree = Rebalance(tmp);
        }
        else *tree = NULL;
    }

    else if ((tmp->left == NULL) || (tmp->right == NULL))  //child 1
    {
        if (tmp->left == NULL)
            child = tmp->right;
        else
            child = tmp->left;
        if (tmp->parent)
        {
            parent = tmp->parent;
            if (parent->left == tmp)
                parent->left = child;
            else
                parent->right = child;
            child->parent = parent;
            *tree = Rebalance(tmp);
        }
        else
        {
            child->parent = NULL;
            *tree = child;
        }
    }

    else //child 2
    {
        successor = SuccessorNode(tmp->right);
        tmpnum = tmp->data;
        tmp->data = successor->data;
        successor->data = tmpnum;
        *tree = Delete(&successor, successor->data);
    }
    return *tree;
}

Node* Search(Node* root, int num)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > num) Search(root->left, num);
    else if (root->data < num) Search(root->right, num);
    else return root;
    //else printf("%d\n", root->data);
}

void Print(Node* root)
{
    if (root == NULL) return;
    printf(" %d", root->data);
    Print(root->left);
    Print(root->right);
}
