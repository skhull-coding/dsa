#include <stdio.h>
#include <stdlib.h>

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

pNode minValue(pNode root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

pNode deleteNode(pNode root, int value)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            pNode temp = root->right;
            free(root);
            root = NULL;
            return temp;
        }
        else if (root->right == NULL)
        {
            pNode temp = root->left;
            free(root);
            root = NULL;
            return temp;
        }
        else
        {
            pNode temp = minValue(root->right);
            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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
    p1 = deleteNode(p1, 5);
    p1 = deleteNode(p1, 56);
    printf("\n");
    inOrderTreeTraversal(p1);

    return 0;
}