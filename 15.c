#include <stdio.h>
#include <stdlib.h>

// circular linked list

typedef struct NODE
{
    int data;
    struct NODE *next;
} Node;
typedef Node *pNode;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void linkNodes(pNode node1, pNode node2)
{
    node1->next = node2;
}

void traverseNode(pNode head)
{
    pNode ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}

pNode insertAtFirst(pNode head, int data)
{
    pNode newNode = createNode(data);
    pNode ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
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
        pNode newNode = createNode(data);
        while (i != index - 1)
        {
            ptr = ptr->next;
            i++;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

pNode insertAtLast(pNode head, int data)
{
    pNode newNode = createNode(data);
    pNode ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    newNode->next = head;
    ptr->next = newNode;

    return head;
}

pNode insertAfterNode(pNode node, int data)
{
    pNode newNode = createNode(data);
    newNode->next = node->next;
    node->next = newNode;
}

pNode deleteAtFirst(pNode head)
{
    pNode ptr = head;

    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    pNode temp = head->next;
    ptr->next = temp;
    free(head);
    head = temp;

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
        while (i != index - 1)
        {
            ptr = ptr->next;
            i++;
        }
        if (ptr->next == head)
        {
            return deleteAtFirst(head);
        }
        pNode temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    return head;
}

pNode deleteAtLast(pNode head)
{
    pNode ptr = head;
    pNode qptr = head->next;

    while (qptr->next != head)
    {
        ptr = ptr->next;
        qptr = qptr->next;
    }
    ptr->next = qptr->next;
    free(qptr);

    return head;
}

pNode deleteAtValue(pNode head, int data)
{
    if (head->data == data)
    {
        return deleteAtFirst(head);
    }
    else
    {
        pNode ptr = head;
        pNode qptr = head->next;
        while (qptr->data != data && qptr->next != head)
        {
            ptr = ptr->next;
            qptr = qptr->next;
        }
        if (qptr->data == data)
        {
            if (qptr == head)
            {
                return deleteAtFirst(head);
            }
            ptr->next = qptr->next;
            free(qptr);
        }
    }
    return head;
}

int getNodeValueByIndex(pNode head, int index)
{
    int i = 0;
    while (i != index)
    {
        head = head->next;
        i++;
    }
    return head->data;
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
    linkNodes(fourth, HEAD);

    traverseNode(HEAD);

    HEAD = insertAtFirst(HEAD, 34);
    traverseNode(HEAD);

    HEAD = insertAtIndex(HEAD, 2, 23);
    traverseNode(HEAD);

    HEAD = insertAtLast(HEAD, 567);
    traverseNode(HEAD);

    insertAfterNode(second, 45);
    traverseNode(HEAD);

    HEAD = deleteAtFirst(HEAD);
    traverseNode(HEAD);

    HEAD = deleteAtIndex(HEAD, 2);
    traverseNode(HEAD);

    HEAD = deleteAtLast(HEAD);
    traverseNode(HEAD);

    HEAD = deleteAtValue(HEAD, 45);
    traverseNode(HEAD);

    printf("%d", getNodeValueByIndex(HEAD, 3));

    return 0;
}