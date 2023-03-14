#include <stdio.h>
#include <stdlib.h>

// Linked List by myself

typedef struct linkedListNode
{
    int data;
    struct linkedListNode *next;
} Node;
typedef Node *pNode;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL; // controlling wild pointers
    return node;
}

void linkNodes(pNode node1, pNode node2)
{
    node1->next = node2;
    node2->next = NULL;
}

void traverseNode(pNode node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    pNode HEAD = createNode(34);
    linkNodes(HEAD, createNode(45));
    linkNodes(HEAD->next, createNode(4));
    linkNodes(HEAD->next->next, createNode(13));

    traverseNode(HEAD);

    return 0;
}