#include <stdio.h>
#include <stdlib.h>

// Linked list

typedef struct Node
{
    int data;
    struct Node *next;
} Node;
typedef Node *node;

void linkedListTraversal(node Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
}

int main()
{
    node head, second, third, fourth;

    head = (node)malloc(sizeof(Node));
    second = (node)malloc(sizeof(Node));
    third = (node)malloc(sizeof(Node));
    fourth = (node)malloc(sizeof(Node));

    head->data = 7;
    head->next = second;

    second->data = 91;
    second->next = third;

    third->data = 23;
    third->next = fourth;

    fourth->data = 34;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
}