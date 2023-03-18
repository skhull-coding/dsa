#include <stdio.h>
#include <stdlib.h>

// Binary Search tree
// It is a type of binary tree

// properties ->
// 1. All nodes of subtree are lesser from root
// 2. All nodes of right subtree are greater from root
// 3. Left and right subtrees are also BST
// 4. There are no duplicate nodes
// 5. In order traversal of a BST gives an ascending sorted array

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
typedef Node *pNode;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Pre Order Traversal
void preOrderTreeTraversal(pNode Root)
{
    if (Root != NULL)
    {
        printf("%d ", Root->data);
        preOrderTreeTraversal(Root->left);
        preOrderTreeTraversal(Root->right);
    }
}

// Post Order Traversal
void postOrderTreeTraversal(pNode Root)
{
    if (Root != NULL)
    {
        postOrderTreeTraversal(Root->left);
        postOrderTreeTraversal(Root->right);
        printf("%d ", Root->data);
    }
}

// In Order Traversal
void inOrderTreeTraversal(pNode Root)
{
    if (Root != NULL)
    {
        inOrderTreeTraversal(Root->left);
        printf("%d ", Root->data);
        inOrderTreeTraversal(Root->right);
    }
}

int isBST(pNode Root)
{
    static pNode prev = NULL;
    if (Root != NULL)
    {
        if (!isBST(Root->left))
        {
            return 0;
        }
        if (prev != NULL && Root->data <= prev->data)
        {
            return 0;
        }
        prev = Root;
        return (isBST(Root->right));
    }
    else
    {
        return 1;
    }
}

// Search in BST
pNode searchBST(pNode root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

pNode searchBSTI(pNode root, int key)
{
    while (root != NULL && root->data != key)
    {
        if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}

// Insertion in BST
void insert(pNode root, int key)
{
    pNode prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Cannot insert %d\n", key);
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    pNode newNode = createNode(key);
    if (key < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}

int main()
{
    pNode p1 = createNode(5);
    pNode p2 = createNode(3);
    pNode p3 = createNode(6);
    pNode p4 = createNode(1);
    pNode p5 = createNode(4);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

    inOrderTreeTraversal(p1);
    printf("\n");

    // printf("\n%d ", isBST(p1));
    // printf("\n%p ", searchBST(p1, 6));
    // printf("\n%p ", searchBSTI(p1, 6));

    insert(p1, 5);
    inOrderTreeTraversal(p1);

    return 0;
}