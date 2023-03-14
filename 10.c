#include <stdio.h>
#include <stdlib.h>

// Insertion in a linked list

typedef struct linkedListNode
{
    int data;
    struct linkedListNode *next;
} Node;
typedef Node *pNode;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node)); // typesetting void pointer
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

pNode insertNode(pNode node, int index, pNode insertNode)
{
    if (index == 0)
    {
        insertNode->next = node;
        node = insertNode;
    }
    else
    {
        int i = 0;
        pNode nodeN = node;
        while (node != NULL)
        {
            if (i == index - 1)
            {
                insertNode->next = node->next;
                node->next = insertNode;
                return nodeN;
            }
            i++;
            node = node->next;
        }
        if (i >= index - 1)
        {
            printf("Couldn't add nodes as the index was too high\n");
        }
        return nodeN;
    }
}

void previewNodes(pNode node)
{
    while (node != NULL)
    {
        printf(" (%d) |@--> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    pNode HEAD, second, third, fourth;

    HEAD = createNode(97);
    second = createNode(956);
    third = createNode(11);
    fourth = createNode(800);

    linkNodes(HEAD, second);
    linkNodes(second, third);
    linkNodes(third, fourth);

    traverseNode(HEAD);

    printf("\n");

    pNode newNode = createNode(34);

    HEAD = insertNode(HEAD, 0, newNode);

    traverseNode(HEAD);
    printf("\n");

    previewNodes(HEAD);

    return 0;
}