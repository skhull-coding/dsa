#include <stdio.h>
#include <stdlib.h>

// Linked list implementation practice
// Types - linear, circular, doubly

// Type 1 - Linear linked list adt
// Data - Nodes [data and and a pointer to another node]

// Operations -
// Insert(-), delete(-), search(-), push(-), pop(-), shift(-), unshift(-), first(-), end(-), isfull(-), isempty(-), creation(-), deletion(-), getlength(-)

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef Node *pNode;

typedef struct LinkedList
{
    pNode Head;
    int length;
} LinkedList;
typedef LinkedList *pLink;

pNode createNode(int data)
{
    pNode node = (pNode)malloc(sizeof(Node));
    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

pLink createLinkedList()
{
    pLink link = (pLink)malloc(sizeof(LinkedList));
    if (link != NULL)
    {
        link->Head = NULL;
        link->length = 0;
        return link;
    }
    return link;
}

int isEmpty(pLink ll)
{
    return !ll->length;
}

int isFull()
{
    pNode temp = createNode(0);
    if (temp != NULL)
    {
        free(temp);
        return 0;
    }
    return 1;
}

void insert(pLink ll, int index, int data)
{
    if (!isFull())
    {
        pNode temp = createNode(data);
        if (index == 0)
        {
            temp->next = ll->Head;
            ll->Head = temp;
        }
        else if (index == ll->length)
        {
            pNode ptr = ll->Head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        else if (index > 0 && index < ll->length)
        {
            int i = 0;
            pNode ptr = ll->Head;
            while (i <= index && ptr->next != NULL)
            {
                i++;
                ptr = ptr->next;
            }
            temp->next = ptr->next;
            ptr->next = temp;
        }
        else
        {
            free(temp);
            ll->length--;
        }
        ll->length++;
    }
}

void push(pLink ll, int data)
{
    insert(ll, ll->length, data);
}

void unshift(pLink ll, int data)
{
    insert(ll, 0, data);
}

int deleteByValue(pLink ll, int value)
{
    int val = -1;
    if (ll->length > 1)
    {
        int data = ll->Head->data;
        pNode ptr = ll->Head;
        while (data != value && ptr->next->next != NULL)
        {
            ptr = ptr->next;
            data = ptr->next->data;
        }
        if (data == value && ptr != ll->Head)
        {
            pNode temp = ptr->next;
            ptr->next = temp->next;
            free(temp);
            val = value;
        }
        else if (data == value && ptr == ll->Head)
        {
            pNode ptr = ll->Head->next;
            free(ll->Head);
            ll->Head = ptr;
            val = value;
        }
    }
    else if (ll->length == 1)
    {
        if (ll->Head->data == value)
        {
            pNode ptr = ll->Head->next;
            free(ll->Head);
            ll->Head = ptr;
            val = value;
        }
    }
    return val;
}

void changeDirn(pLink ll, pNode ptr)
{
    if (ptr != NULL)
    {
        pNode temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        ll->length--;
    }
}

int deleteByIndex(pLink ll, int index)
{
    int val = -1;
    if (!isEmpty(ll))
    {

        if (index == 0)
        {
            val = ll->Head->data;
            pNode temp = ll->Head->next;
            free(ll->Head);
            ll->Head = temp;
            ll->length--;
        }
        else if (index == ll->length - 1)
        {
            pNode ptr = ll->Head;
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            val = ptr->next->data;
            changeDirn(ll, ptr);
        }

        else if (index < ll->length)
        {
            int i = 1;
            pNode ptr = ll->Head;
            while (ptr->next != NULL && i != index)
            {
                ptr = ptr->next;
                i++;
            }
            if (i == index)
            {
                val = ptr->next->data;
                changeDirn(ll, ptr);
            }
        }
    }
    return val;
}

int pop(pLink ll)
{
    return deleteByIndex(ll, ll->length - 1);
}

int shift(pLink ll)
{
    return deleteByIndex(ll, 0);
}

void clearLinkedList(pLink ll)
{
    while (!isEmpty(ll))
    {
        pop(ll);
    }
    free(ll);
    ll = NULL;
}

pNode linearSearch(pLink ll, int value)
{
    if (!isEmpty(ll))
    {
        int data = ll->Head->data;
        pNode ptr = ll->Head;
        while (data != value && ptr->next != NULL)
        {
            ptr = ptr->next;
            data = ptr->data;
        }
        if (data == value)
        {
            return ptr;
        }
    }
    return NULL;
}

int getLength(pLink ll)
{
    return ll->length;
}

int firstVal(pLink ll)
{
    if (!isEmpty(ll))
    {
        return ll->Head->data;
    }
    return -1;
}

int lastVal(pLink ll)
{
    if (!isEmpty(ll))
    {
        pNode ptr = ll->Head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        return ptr->data;
    }
    return -1;
}

void printLinkedList(pLink ll)
{
    if (!isEmpty(ll))
    {
        printf("List : ");
        pNode ptr = ll->Head;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    pLink link = createLinkedList();

    insert(link, 0, 23);
    insert(link, 0, 13);
    insert(link, 0, 3);
    insert(link, 0, -3);
    pop(link);
    pop(link);
    pop(link);
    pop(link);
    pop(link);
    unshift(link, 23);
    unshift(link, 22);
    unshift(link, 25);
    unshift(link, 24);
    unshift(link, 21);
    shift(link);
    printf("%d %d ", firstVal(link), lastVal(link));

    printLinkedList(link);

    return 0;
}