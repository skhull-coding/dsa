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

// Trick to find inorder, preorder, postorder traversal
// pre - line on left
// post - line on right
// in - line on bottom

int main()
{
    pNode p1 = createNode(4);
    pNode p2 = createNode(1);
    pNode p3 = createNode(6);
    pNode p4 = createNode(5);
    pNode p5 = createNode(2);

    p1->left = p2;
    p1->right = p3;

    p2->left = p4;
    p2->right = p5;

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