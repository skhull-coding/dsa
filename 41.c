#include <stdio.h>
#include <stdlib.h>

// Representation of a binary tree
// 1. Array Representation
// 2. Linked Representation - using doubly linked list

// structure of a node in C lang
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

int main()
{
    pNode p = createNode(2);  // constructing the root node
    pNode p1 = createNode(1); // constructing the second node
    pNode p2 = createNode(4); // constructing the third node

    // Linking the nodes
    p->left = p1;
    p->right = p2;

    return 0;
}