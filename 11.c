#include <stdio.h>
#include <stdlib.h>

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
    printf("\n");
}

pNode insertAtFirst(pNode head, int data)
{
    pNode node = createNode(data);
    node->next = head;
    head = node;
    return head;
}

pNode insertAtIndex(pNode head, int data, int index)
{
    pNode node = createNode(data);
    pNode temp = head;
    int i = 0;
    while (i != index - 1)
    {
        temp = temp->next;
        i++;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}

pNode insertAtEnd(pNode head, int data)
{
    pNode node = createNode(data);
    pNode temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

pNode insertAfterNode(pNode head, pNode prevNode, int data)
{
    pNode node = createNode(data);
    node->next = prevNode->next;
    prevNode->next = node;
    return head;
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

    HEAD = insertAtFirst(HEAD, 23);
    traverseNode(HEAD);

    HEAD = insertAtIndex(HEAD, 2300, 3);
    traverseNode(HEAD);

    HEAD = insertAtEnd(HEAD, 78);
    traverseNode(HEAD);

    HEAD = insertAfterNode(HEAD, second, 23400);
    traverseNode(HEAD);

    return 0;
}