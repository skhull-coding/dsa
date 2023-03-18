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

int isBST(pNode Root){
    static pNode prev = NULL;
    if (Root!=NULL){
        if (!isBST(Root->left)){
            return 0;
        }
        if (prev!=NULL && Root->data<=prev->data){
            return 0;
        }
        prev = Root;
        return (isBST(Root->right));
    }else{
        return 1;
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

    printf("\n%d ", isBST(p1));

    return 0;
}