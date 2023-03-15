#include <stdio.h>
#include <stdlib.h>

// Deletion cases of linked lists
// Delete at first index
// Delete at a given index
// Delete at last index
// Delete at a given value

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

pNode deleteAtFirstIndex(pNode head)
{
    pNode temp = head;
    head = head->next;
    free(temp);
    temp = NULL; // for no dangling pointers
    return head;
}

pNode deleteAtIndex(pNode head, int index)
{
    pNode ptr = head;
    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    pNode temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    temp = NULL;
    return head;
}

pNode deleteAtLast(pNode head)
{
    pNode ptr = head, q = ptr->next;
    while (q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = NULL;
    free(q);
    q = NULL;
    return head;
}

pNode deleteAtValue(pNode head, int value)
{
    pNode ptr = head;

    if (ptr->data == value)
    {
        head = deleteAtFirstIndex(head);
        return head;
    }

    while (ptr->next->data != value)
    {
        ptr = ptr->next;
    }

    pNode temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
    temp = NULL;

    return head;
}

int main()
{
    pNode HEAD, second, third, fourth;

    HEAD = createNode(1);
    second = createNode(2);
    third = createNode(3);
    fourth = createNode(4);

    linkNodes(HEAD, second);
    linkNodes(second, third);
    linkNodes(third, fourth);
    linkNodes(fourth, createNode(5));
    linkNodes(fourth->next, createNode(6));

    traverseNode(HEAD);

    HEAD = deleteAtFirstIndex(HEAD);
    traverseNode(HEAD);

    HEAD = deleteAtIndex(HEAD, 4);
    traverseNode(HEAD);

    HEAD = deleteAtLast(HEAD);
    traverseNode(HEAD);

    HEAD = deleteAtValue(HEAD, 2);
    traverseNode(HEAD);

    return 0;
}