#include <stdio.h>
#include <stdlib.h>

// Doubly linked list

typedef struct NODE
{
    struct NODE *prev;
    int data;
    struct NODE *next;
} Node;
typedef Node *pNode;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void linkNodes(pNode node1, pNode node2)
{
    node1->next = node2;
    node2->prev = node1;
}

void traverseNodes(pNode head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void traverseNodesReverse(pNode node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->prev;
    }
    printf("\n");
}

void traverseReverse(pNode head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
    printf("\n");
}

pNode insertAtFirst(pNode head, int data)
{
    pNode newNode = createNode(data);
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

pNode insertAtIndex(pNode head, int index, int data)
{

    if (index == 0)
    {
        return insertAtFirst(head, data);
    }

    else
    {
        int i = 0;
        pNode ptr = head;
        while (i != index - 1 && ptr != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        if (ptr != NULL)
        {
            pNode qptr = ptr->next;
            pNode newNode = createNode(data);

            ptr->next = newNode;
            newNode->prev = ptr;

            newNode->next = qptr;
            if (qptr != NULL)
            {
                qptr->prev = newNode;
            }
        }
    }

    return head;
}

pNode insertAtLast(pNode head, int data)
{
    pNode newNode = createNode(data);
    pNode ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;

    return head;
}

void insertAfter(pNode node1, int data)
{
    pNode newNode = createNode(data);

    pNode qptr = node1->next;

    node1->next = newNode;
    newNode->prev = node1;

    newNode->next = qptr;
    if (qptr != NULL)
    {
        qptr->prev = newNode;
    }
}

pNode deleteAtFirst(pNode head)
{
    pNode temp = head->next;
    temp->prev = NULL;
    free(head);
    head = temp;

    return head;
}

pNode deleteAtLast(pNode head)
{
    pNode ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    pNode prevPtr = ptr->prev;

    prevPtr->next = NULL;
    free(ptr);
    ptr = NULL;

    return head;
}

pNode deleteAtIndex(pNode head, int index)
{
    if (index == 0)
    {
        return deleteAtFirst(head);
    }
    else
    {
        pNode ptr = head;
        int i = 0;
        while (i != index && ptr != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        if (ptr != NULL)
        {
            pNode prevNode = ptr->prev;
            pNode nextNode = ptr->next;

            free(ptr);
            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }
            prevNode->next = nextNode;
        }
    }
    return head;
}

pNode deleteAtValue(pNode head, int value)
{
    if (head->data == value)
    {
        return deleteAtFirst(head);
    }
    else
    {
        pNode ptr = head->next;
        while (ptr->data != value && ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->data == value)
        {
            pNode prevNode = ptr->prev;
            pNode nextNode = ptr->next;

            free(ptr);
            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }
            prevNode->next = nextNode;
        }
    }
    return head;
}

// Searching would be done by linear search.

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

    traverseNodes(HEAD);
    // traverseReverse(HEAD);
    // traverseNodesReverse(fourth);

    HEAD = insertAtFirst(HEAD, 12);
    traverseNodes(HEAD);
    // traverseNodesReverse(fourth);

    HEAD = insertAtIndex(HEAD, 2, 87);
    traverseNodes(HEAD);
    // traverseReverse(HEAD);

    HEAD = insertAtLast(HEAD, 32);
    traverseNodes(HEAD);
    // traverseReverse(HEAD);

    insertAfter(third, 67);
    traverseNodes(HEAD);

    HEAD = deleteAtFirst(HEAD);
    traverseNodes(HEAD);

    HEAD = deleteAtLast(HEAD);
    traverseNodes(HEAD);

    HEAD = deleteAtIndex(HEAD, 1);
    traverseNodes(HEAD);

    HEAD = deleteAtValue(HEAD, 67);
    traverseNodes(HEAD);

    return 0;
}