#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key, height;
    struct Node *left;
    struct Node *right;
} Node;
typedef Node *pNode;

pNode createNode(int key)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->key = key;
    node->height = 1;
    node->left = node->right = NULL;
    return node;
}

int getHeight(pNode node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int getBalancedFactor(pNode node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

pNode rightRotate(pNode y)
{
    pNode x = y->left;
    pNode t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return x;
}

pNode leftRotate(pNode x)
{
    pNode y = x->right;
    pNode t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

pNode insert(pNode node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }

    if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else if (key < node->key)
    {
        node->left = insert(node->left, key);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    int bf = getBalancedFactor(node);

    if (bf > 1 && node->left->key > key)
    {
        return rightRotate(node);
    }
    else if (bf < -1 && node->right->key < key)
    {
        return leftRotate(node);
    }
    else if (bf > 1 && node->left->key < key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    else if (bf < -1 && node->right->key > key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrderTreeTraversal(pNode Root)
{
    if (Root != NULL)
    {
        printf("%d ", Root->key);
        preOrderTreeTraversal(Root->left);
        preOrderTreeTraversal(Root->right);
    }
}

int main()
{
    pNode root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    preOrderTreeTraversal(root);

    return 0;
}