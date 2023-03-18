#include <stdio.h>
#include <stdlib.h>

// Traversal in a binary tree
// 1. PreOrder Traversal -> (Root-left-right)
// 2. PostOrder Traversal -> (left-right-Root)
// 3. InOrder Traversal -> (left-Root-right)

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

void preOrderTreeTraversal(pNode Root)
{
    if (Root == NULL)
    {
        return;
    }
    printf("%d ", Root->data);
    preOrderTreeTraversal(Root->left);
    preOrderTreeTraversal(Root->right);
}

void postOrderTreeTraversal(pNode Root)
{
    if (Root == NULL)
    {
        return;
    }
    postOrderTreeTraversal(Root->left);
    postOrderTreeTraversal(Root->right);
    printf("%d ", Root->data);
}

void inOrderTreeTraversal(pNode Root)
{
    if (Root == NULL)
    {
        return;
    }
    inOrderTreeTraversal(Root->left);
    printf("%d ", Root->data);
    inOrderTreeTraversal(Root->right);
}

int main()
{
    pNode p1 = createNode(31);
    pNode p2 = createNode(1);
    pNode p3 = createNode(14);
    pNode p4 = createNode(2);
    pNode p5 = createNode(4);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p3->right = p5;

    printf("Pre Order : \t");
    preOrderTreeTraversal(p1);
    printf("\n");

    printf("Post Order : \t");
    postOrderTreeTraversal(p1);
    printf("\n");

    printf("In Order : \t");
    inOrderTreeTraversal(p1);
    printf("\n");

    return 0;
}